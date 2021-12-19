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
	 * @brief The default constructer for Drones
	 *
	 * @return a drone object
	 */
	ManualMovement();
	
	/**
	 * @brief an overloaded constructer for Drones
	 *
	 * @return a drone object
	 */
	void AlterVelocity(Vector3& dir, Vector3& vel);
	
	/**
	 * @brief an overloaded constructer for Drones
	 *
	 * @return a drone object
	 */
	void ChangeKeys(int* arr);
	

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
