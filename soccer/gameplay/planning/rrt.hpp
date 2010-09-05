// kate: indent-mode cstyle; indent-width 4; tab-width 4; space-indent false;
// vim:ai ts=4 et

#pragma once

#include <list>
#include <Geometry2d/Point.hpp>
#include <framework/Obstacle.hpp>
#include <framework/Path.hpp>
#include <framework/Dynamics.hpp>

#include <QPainter>

#include "Tree.hpp"

namespace Planning
{
	class Dynamics;
	
	namespace RRT
	{
		/** generate a random point on the floor */
		Geometry2d::Point randomPoint();
		
		class Planner
		{			
			public:
				Planner();
				
				int maxIterations() const
				{
					return _maxIterations;
				}
				
				void maxIterations(int value)
				{
					_maxIterations = value;
				}
				
				void setDynamics(Dynamics* dynamics)
				{
					_dynamicsTree.dynamics = dynamics;
				}
				
				//run the path planner
				//this will always populate path to be the path we need to travel
				void run(
						const Geometry2d::Point& start,
						const float angle, 
						const Geometry2d::Point& vel, 
						const Geometry2d::Point& goal, 
						const ObstacleGroup* obstacles, 
						Planning::Path &path);
				
				/** returns the length of the best position planned path */
				float fixedPathLength() const { return _bestPath.length(); }
				
				void draw(QPainter& painter);
		
		protected:
			DynamicsTree _dynamicsTree;
			
			FixedStepTree _fixedStepTree0;
			FixedStepTree _fixedStepTree1;
			
			/** best goal point */
			Geometry2d::Point _bestGoal;
			
			//best planned path
			//this is a fixed step path
			Planning::Path _bestPath;
			
			//maximum number of rrt iterations to run
			//this does not include connect attemps
			unsigned int _maxIterations;
			
			//latest obstacles
			const ObstacleGroup* _obstacles;
			
			/** makes a path from the last point of each tree
			 *  If the points don't match up...fail!
			 *  The final path will be from the start of tree0
			 *  to the start of tree1 */
			void makePath();
			
			/** optimize the path */
			void optimize(Planning::Path &path, const ObstacleGroup *obstacles);
		};
	}
}