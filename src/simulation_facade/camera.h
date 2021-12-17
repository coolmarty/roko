/**
 * @file camera.h
 *
 */
 #ifndef CAMERA_H_
 #define CAMERA_H_
 /*******************************************************************************
  * Includes
  ******************************************************************************/
#include "camera_controller.h"
#include <iostream>
#include <fstream>
#include "image_processing.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class of Camera
 *
 *
 */
class Camera : public ICameraObserver {
public:
    // results of blob detection
    struct CameraResult : public ICameraResult {
        bool found;
        double pos[3];
    };

    /**
     * @brief The main constructor of Camera, takes in an id and controller
     *
     *
     */
    Camera(int cameraId, ICameraController* controller) : id(id), controller(controller){
        controller->AddObserver(*this);
    };

    /**
     * @brief Takes a picture of a camera with a certain id
     *
     *
     */
    void TakePicture() {
        controller->TakePicture(id);
    }

    /**
     * @brief async image processing call
     *
     *
     */
    ICameraResult* ProcessImages(int cameraId, double xPos, double yPos, double zPos, const std::vector<RawCameraImage>& images, picojson::object& details) const {
        if (cameraId == id || cameraId < 0) {
            // These will output the image to files.  Ultimately this is just for debugging:
            std::ofstream colorFile ("color.jpg", std::ios::out | std::ios::binary);
            colorFile.write (reinterpret_cast<const char*>(images[0].data), images[0].length);
            std::ofstream depthFile ("depth.jpg", std::ios::out | std::ios::binary);
            depthFile.write (reinterpret_cast<const char*>(images[1].data), images[1].length);

            // Use the following to convert color and depth images to RGBA image from memory (inside your image class / perhaps with a new constructor):
            // int width, height, components;
            // unsigned char* buffer = stbi_load_from_memory((const unsigned char*)images[0].data, images[0].length(), &width, &height, &components, 4);
            // components = 4;

            // Generate the result of image processing.  This could include images using the Result class.
            CameraResult* result = new CameraResult();
			
			ImageProcessing* processor = new ImageProcessing();
			
            result->found = processor->BlobCheck("color.jpg");
			
			std::vector<float> dir= processor->BlobGetDirection("color.jpg", "depth.jpg");
			float dist = processor->BlobGetDistance("color.jpg", "depth.jpg");
            result->pos[0] = xPos + dist * dir.at(0);
            result->pos[1] = yPos + dist * dir.at(1);
            result->pos[2] = zPos + dist * dir.at(2);
			
			delete processor;
            return result;
        }
        else {
            return NULL;
        }
    }

    /**
     * @brief result of image processing
     *
     *
     */
    void ImageProcessingComplete(ICameraResult* result) {
        CameraResult& res = *static_cast<CameraResult*>(result);
        if (res.found) {
            std::cout << "The robot was found here: " << res.pos[0] << ", " << res.pos[1] << ", " << res.pos[1] << std::endl;
        }
        delete result;
    }

    ICameraController* controller;
    int id;
};

#endif
