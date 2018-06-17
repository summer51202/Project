#include "stick.h"

Stick::Stick(float x, float y, float w, float d, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(w,d);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);

    b2PolygonShape bodyshape;
    bodyshape.SetAsBox(w/1.9,d/1.9);

    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = STICK_DENSITY;
    fixturedef.friction = STICK_FRICTION;
    fixturedef.restitution = STICK_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}

b2Vec2 Stick::GetLinearVelocity()
{
    return g_body->GetLinearVelocity();
}

b2Vec2 Stick::GetOriginPosition()
{
    return g_body->GetPosition();
}

bool Stick::DetectBound()
{
     if (GetOriginPosition().x >= 32.0f || GetOriginPosition().x < 0.0f ||GetOriginPosition().y > 18.0f || GetOriginPosition().y < 0.0f)  return true;
     return false;
}
