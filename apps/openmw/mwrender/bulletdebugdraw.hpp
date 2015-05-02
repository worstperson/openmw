#ifndef OPENMW_MWRENDER_BULLETDEBUGDRAW_H
#define OPENMW_MWRENDER_BULLETDEBUGDRAW_H

#include "btBulletDynamicsCommon.h"

#include <osg/ref_ptr>
#include <osg/Array>
#include <osg/PrimitiveSet>

namespace osg
{
    class Group;
    class Geode;
    class Geometry;
}

namespace MWRender
{

class DebugDrawer : public btIDebugDraw
{
protected:
    osg::ref_ptr<osg::Group> mParentNode;
    btDynamicsWorld *mWorld;
    osg::ref_ptr<osg::Geode> mGeode;
    osg::ref_ptr<osg::Geometry> mGeometry;
    osg::ref_ptr<osg::Vec3Array> mVertices;
    osg::ref_ptr<osg::DrawArrays> mDrawArrays;

    bool mDebugOn;

public:

    DebugDrawer(osg::ref_ptr<osg::Group> parentNode, btDynamicsWorld *world);
    ~DebugDrawer();

    void step();

    void drawLine(const btVector3& from,const btVector3& to,const btVector3& color);

    void drawContactPoint(const btVector3& PointOnB,const btVector3& normalOnB,btScalar distance,int lifeTime,const btVector3& color);

    void reportErrorWarning(const char* warningString);

    void draw3dText(const btVector3& location,const char* textString) {}

    //0 for off, anything else for on.
    void setDebugMode(int isOn);

    //0 for off, anything else for on.
    int getDebugMode() const;

};


}

#endif