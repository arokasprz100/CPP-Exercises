#ifndef Angle_h
#define Angle_h

class Angle
{
public:
    explicit Angle (double radians);
    double rad() const;
    double deg() const;
    double& deg();
    static Angle distance (const Angle& angle1, const Angle& angle2);
    operator double() const;

private:
    double angleValueDeg;
};

#endif // Angle_h
