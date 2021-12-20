/**
 * @file manual_movement.h
 *
 */

#ifndef MANUAL_MOVEMENT_H_
#define MANUAL_MOVEMENT_H_


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "vector3.h"
#include "matrix3.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class ManualMovement {
public:
    /**
	 * @brief The default constructer for ManualMovement
	 *
	 * 
	 */
	ManualMovement();
	
	/**
	 * @brief Changes velocity
	 *
	 * 
	 */
	void AlterVelocity(Vector3& dir, Vector3& vel);
	
	/**
	 * @brief Changes list of active keys
	 *
	 * 
	 */
	void ChangeKeys(int* arr);
	
	/**
	 * @brief Sets y rotation tracking angle
	 *
	 * 
	 */
	void SetAng(float angle) {ang = angle;}
	

private:
    /*
	* @Used to keep an array of currently active keys
	*/
	int keys[4];
	
	/*
	* @brief Constant unit of rotation stored to avoid recalculation.
	*/
	Matrix3 xPosRot;
	
	/*
	* @brief Constant unit of rotation stored to avoid recalculation. 
	*/
	Matrix3 yPosRot;
	
	/*
	* @brief Constant unit of rotation stored to avoid recalculation. 
	*/
	Matrix3 zPosRot;
	
	/*
	* @brief Constant unit of rotation stored to avoid recalculation. 
	*/
	Matrix3 xNegRot;
	
	/*
	* @brief Constant unit of rotation stored to avoid recalculation. 
	*/
	Matrix3 yNegRot;
	
	/*
	* @brief Constant unit of rotation stored to avoid recalculation. 
	*/
	Matrix3 zNegRot;
	
	/*
	* @brief Matrix roation used to return to original state.
	*/
	Matrix3 toWorld;
	
	/*
	* @brief Flag used to determine whether or not current speed is opposite or parallel to direction
	*/
	bool flag;
	
	/*
	* @brief used to track rotation along the y axis
	*/
	float ang;
};

#endif
