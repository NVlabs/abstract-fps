#pragma once
#include <G3D/G3D.h>

class PhysicsScene : public Scene {
protected:
    Vector3 m_gravity;
	float m_resetHeight = fnan();

    /** Polygons of all non-dynamic entitys */
    shared_ptr<TriTree>                     m_collisionTree;

    PhysicsScene(const shared_ptr<AmbientOcclusion>& ao) : Scene(ao) {
        m_collisionTree = TriTree::create(false);
    }

public:

    static shared_ptr<PhysicsScene> create(const shared_ptr<AmbientOcclusion>& ao);

    void poseExceptExcluded(Array<shared_ptr<Surface> >& surfaceArray, const String& excludedEntity);

    void setGravity(const Vector3& newGravity) { m_gravity = newGravity; }
    void setResetHeight(const float resetHeight) { m_resetHeight = resetHeight;  }

	float resetHeight() { return m_resetHeight; }
    Vector3 gravity() const { return m_gravity; }

    /** Extend to read in physics properties */
    virtual Any load(const String& sceneName, const LoadOptions& loadOptions = LoadOptions()) override;

    /** Gets all static triangles within this world-space sphere. */
    void staticIntersectSphere(const Sphere& sphere, Array<Tri>& triArray) const;

    /** Gets all static triangles within this world-space box. */
    void staticIntersectBox(const AABox& box, Array<Tri>& triArray) const;

    const CPUVertexArray& vertexArrayOfCollisionTree() const {
        return m_collisionTree->vertexArray();
    }

     Any toAny() const;

};
