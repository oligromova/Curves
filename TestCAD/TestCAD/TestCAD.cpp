#include <iostream>
#include <vector>
#include <random>
#include <memory>

#include "Circle2D.h"
#include "Ellipse2D.h"
#include "Helix3D.h"

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

void task3(std::shared_ptr<Curve> curve)
{
    double t = M_PI / 4;
    switch (curve->curveType())
    {
    case CurveType::Circle2D:
    {
        std::cout << "Circle2D:" << std::endl;
        break;
    }
    case CurveType::Ellipse2D:
    {
        std::cout << "Ellipse2D:" << std::endl;
        break;
    }
    case CurveType::Helix3D:
    {
        std::cout << "Helix3D:" << std::endl;
        break;
    }
    default:
        break;
    }
    std::cout << "coordinate: {" << curve->getPoint(t) << "} " << "derivative: {" << curve->get3DVector(t) << "}" << std::endl;
}

bool cmp_circles(const std::shared_ptr<Circle2D> circle1, const std::shared_ptr<Circle2D> circle2) {
    return circle1->getRadius() < circle2->getRadius();
}

int main()
{
    double max_val_for_rand = 100000;
    double min_val_for_rand = 1;

    /* 2. Populate a container (e.g. vector or list) of objects of these types created in random manner with
          random parameters. */
    std::vector <std::shared_ptr<Curve>> curves;
    for (int i = 0; i < 100; ++i)
    {
        std::random_device rand;
        int rand_numb = rand() % 3;
        switch (rand_numb)
        {
        case 0:
        {
            double r = fRand(min_val_for_rand, max_val_for_rand);
            std::shared_ptr<Curve> circle(new Circle2D{ r });
            curves.push_back(circle);
            break;
        }
        case 1:
        {
            double r1 = fRand(min_val_for_rand, max_val_for_rand);
            double r2 = fRand(min_val_for_rand, max_val_for_rand);
            std::shared_ptr<Curve> ellipse(new Ellipse2D{ r1, r2 });
            curves.push_back(ellipse);
            break;
        }
        case 2:
        {
            double r = fRand(min_val_for_rand, max_val_for_rand);
            double step = fRand(0, 2 * M_PI);
            std::shared_ptr<Curve> helix(new Helix3D{ r, step });
            curves.push_back(helix);
            break;
        }
        default:
            break;
        }

    }
    // 3. Print coordinates of points and derivatives of all curves in the container at t=PI/4.
    for (auto i : curves)
    {
        task3(i);
        std::cout << std::endl;
    }
    /* 4. Populate a second container that would contain only circles from the first container. Make sure the
    second container shares (i.e. not clones) circles of the first one, e.g. via pointers.*/
    std::vector <std::shared_ptr<Circle2D>> circles;
    for (auto i : curves)
    {
        if (i->curveType() == CurveType::Circle2D)
        {
            circles.push_back(std::dynamic_pointer_cast<Circle2D, Curve>(i));
        }
    }
    /* 5. Sort the second container in the ascending order of circles’ radii. That is, the first element has the
    smallest radius, the last - the greatest.*/
    std::sort(circles.begin(), circles.end(), cmp_circles);
    /* 6. Compute the total sum of radii of all curves in the second container.*/
    double radius_sum = 0;
    for (auto i : circles)
    {
        radius_sum += i->getRadius();
    }
    return 0;
}

