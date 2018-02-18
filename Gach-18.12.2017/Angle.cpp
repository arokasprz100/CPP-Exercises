#include "Angle.h"
#include <cmath>

#define M_PI 3.14159265358979323846

double pi = M_PI;

Angle::Angle (double radians)
{
    while (true)
    {
        if (radians>=2*pi)
            radians-=2*pi;
        else if (radians <0)
            radians+=2*pi;
        else
            break;
    }
    //radian = stopnie * PI / 180
    // stopnie = radian * 180 / PI
    angleValueDeg = radians * 180 / pi;
}

double Angle::rad() const
{
    return angleValueDeg*pi/180;
}

double Angle::deg() const
{
    return angleValueDeg;
}

double& Angle::deg()
{
    return angleValueDeg;
}

Angle Angle::distance (const Angle& angle1, const Angle& angle2)
{
    double dist= -fabs(angle1.deg() - angle2.deg());
    dist = dist * pi/180;
    return Angle (dist);
}

Angle::operator double() const
{
    return angleValueDeg;
}
