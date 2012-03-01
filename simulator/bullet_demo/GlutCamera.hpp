#pragma once

#include "GlutDefs.hpp"
#include <GLDebugDrawer.h>
#include "GL_ShapeDrawer.h"

#include "Physics/SimEngine.hpp"

class btCollisionShape;
class btDynamicsWorld;
class btRigidBody;
class btTypedConstraint;

class GlutCamera {
protected:
	float _cameraDistance;
	float _ele;
	float _azi;
	btVector3 _cameraPosition;
	btVector3 _cameraTargetPosition; //look at
	float _scaleBottom;
	float _scaleFactor;
	btVector3 _cameraUp;
	int _forwardAxis;
	int _glutScreenWidth;
	int _glutScreenHeight;
	float _frustumZNear;
	float _frustumZFar;
	int _ortho;
	GL_ShapeDrawer* _shapeDrawer;
	bool _enableshadows;
	btVector3 _sundirection;

	GLDebugDrawer _debugDrawer;

	// connect to dynamics - not created internally
	SimEngine *_simEngine;

public:
	GlutCamera(SimEngine* engine = 0);
	~GlutCamera();

	bool setTexturing(bool enable) { return (_shapeDrawer->enableTexture(enable)); }
	bool setShadows(bool enable) {
		bool p = _enableshadows;
		_enableshadows = enable;
		return (p);
	}

	bool getTexturing() const { return _shapeDrawer->hasTextureEnabled(); }
	bool getShadows() const {	return _enableshadows; }

	void setAzi(float azi) { _azi = azi; }

	void setCameraUp(const btVector3& camUp) { _cameraUp = camUp; }
	void setCameraForwardAxis(int axis) {	_forwardAxis = axis;	}

	void setCameraPosition(const btVector3& pos) { _cameraPosition = pos; }
	btVector3 getCameraPosition() const { return _cameraPosition; }

	void setCameraTargetPosition(const btVector3& pos) { _cameraTargetPosition = pos; }
	btVector3 getCameraTargetPosition() const {	return _cameraTargetPosition; }

	GL_ShapeDrawer* shapeDrawer() { return _shapeDrawer; }
	GLDebugDrawer* debugDrawer() { return &_debugDrawer; }

	void setFrustumZPlanes(float zNear, float zFar) {
		_frustumZNear = zNear;
		_frustumZFar = zFar;
	}

	virtual void myinit(); // initializes camera

	// performs camera updates - can be customized for different camera modes
	virtual void updateCamera();

	void setCameraDistance(float dist) { _cameraDistance = dist; }
	float getCameraDistance() const {	return _cameraDistance; }

	void renderscene(int pass, int debugMode);

	virtual void reshape(int w, int h);   /// Rerender due to resizing the window

	virtual void displayCallback() {}

	virtual void renderme(int debugMode);

	virtual void swapBuffers();

	btVector3 getRayTo(int x, int y);

	void displayProfileString(int xOffset, int yStart, char* message);

	// allow for drawing to screen without projection
	void setOrthographicProjection();
	void resetPerspectiveProjection();

	void chaseCamera();

}; // \class GlutCamera
