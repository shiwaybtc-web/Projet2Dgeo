#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <iostream>

int main() {

    // ==========================================
    //              TESTS TRIANGLE
    // ==========================================
    std::cout << "========== TESTS TRIANGLE ==========" << std::endl;

    std::cout << "\n--- Test perimeter() ---" << std::endl;
    Triangle t1(Point(0, 0), Point(3, 0), Point(0, 4));
    std::cout << "Triangle 3-4-5, attendu = 12, obtenu = " << t1.perimeter() << std::endl;

    std::cout << "\n--- Test area() ---" << std::endl;
    Triangle t4(Point(0, 0), Point(10, 0), Point(0, 10));
    std::cout << "Triangle rectangle, attendu = 50, obtenu = " << t4.area() << std::endl;

    std::cout << "\n--- Test center() ---" << std::endl;
    Triangle t6(Point(0, 0), Point(6, 0), Point(3, 6));
    Point c = t6.center();
    std::cout << "Attendu (3, 2), obtenu = (" << c.x << ", " << c.y << ")" << std::endl;

    std::cout << "\n--- Test translate() ---" << std::endl;
    Triangle t7(Point(0, 0), Point(10, 0), Point(5, 10));
    t7.translate(Point(50, 50));
    std::cout << "Translaté de (50,50), A = (" << t7.A.x << ", " << t7.A.y << ")" << std::endl;
    t7.draw();

    Triangle t7b(Point(100, 100), Point(110, 100), Point(105, 110));
    t7b.translate(Point(-50, -50));
    std::cout << "Translaté de (-50,-50), A = (" << t7b.A.x << ", " << t7b.A.y << ")" << std::endl;
    t7b.draw();

    Triangle t7c(Point(20, 20), Point(40, 20), Point(30, 40));
    t7c.translate(Point(0, 0));
    std::cout << "Translaté de (0,0), A = (" << t7c.A.x << ", " << t7c.A.y << ") (doit pas bouger)" << std::endl;
    t7c.draw();

    std::cout << "\n--- Test resize() ---" << std::endl;
    Triangle t8(Point(0, 0), Point(10, 0), Point(5, 10));
    t8.resize(2);
    std::cout << "Agrandi x2" << std::endl;
    t8.draw();

    Triangle t9(Point(0, 0), Point(10, 0), Point(5, 10));
    t9.resize(0.5);
    std::cout << "Réduit x0.5" << std::endl;
    t9.draw();

    Triangle t9b(Point(0, 0), Point(10, 0), Point(5, 10));
    t9b.resize(1);
    std::cout << "Resize x1 (taille identique)" << std::endl;
    t9b.draw();

    std::cout << "\n--- Test rotate() ---" << std::endl;
    Triangle t10(Point(0, 0), Point(100, 0), Point(50, 100));
    t10.rotate(45);
    std::cout << "Tourné de 45 degrés" << std::endl;
    t10.draw();

    Triangle t10b(Point(0, 0), Point(100, 0), Point(50, 100));
    t10b.rotate(90);
    std::cout << "Tourné de 90 degrés" << std::endl;
    t10b.draw();

    Triangle t10c(Point(0, 0), Point(100, 0), Point(50, 100));
    t10c.rotate(360);
    std::cout << "Tourné de 360 degrés (retour à l'origine)" << std::endl;
    t10c.draw();

    std::cout << "\n--- Test equals() ---" << std::endl;
    Triangle t11(Point(0, 0), Point(3, 0), Point(0, 4));
    Triangle t12(Point(0, 0), Point(3, 0), Point(0, 4));
    std::cout << "Triangles identiques, attendu = true, obtenu = "
        << (t11.equals(t12) ? "true" : "false") << std::endl;

    Triangle t13(Point(0, 0), Point(3, 0), Point(0, 4));
    Triangle t14(Point(1, 1), Point(4, 1), Point(1, 5));
    std::cout << "Triangles différents, attendu = false, obtenu = "
        << (t13.equals(t14) ? "true" : "false") << std::endl;

    std::cout << "\n--- Test isRightAngled() ---" << std::endl;
    Triangle t17(Point(0, 0), Point(3, 0), Point(0, 4));
    std::cout << "Triangle 3-4-5 (rectangle), obtenu = "
        << (t17.isRightAngled() ? "true" : "false") << std::endl;

    Triangle t18(Point(0, 0), Point(10, 0), Point(5, 8.66));
    std::cout << "Triangle équilatéral (pas rectangle), obtenu = "
        << (t18.isRightAngled() ? "true" : "false") << std::endl;

    std::cout << "\n--- Test isEquilateral() ---" << std::endl;
    Triangle t20(Point(0, 0), Point(10, 0), Point(5, 8.66));
    std::cout << "Triangle équilatéral, obtenu = "
        << (t20.isEquilateral() ? "true" : "false") << std::endl;

    Triangle t21(Point(0, 0), Point(3, 0), Point(0, 4));
    std::cout << "Triangle 3-4-5 (pas équilatéral), obtenu = "
        << (t21.isEquilateral() ? "true" : "false") << std::endl;

    Triangle t22(Point(0, 0), Point(5, 0), Point(2.5, 4.33));
    std::cout << "Autre triangle équilatéral, obtenu = "
        << (t22.isEquilateral() ? "true" : "false") << std::endl;

    std::cout << "\n--- Test isIsoceles() ---" << std::endl;
    Triangle t23(Point(0, 0), Point(4, 0), Point(2, 3));
    std::cout << "Triangle isocèle, obtenu = "
        << (t23.isIsoceles() ? "true" : "false") << std::endl;

    Triangle t24(Point(0, 0), Point(3, 0), Point(0, 4));
    std::cout << "Triangle 3-4-5 (pas isocèle), obtenu = "
        << (t24.isIsoceles() ? "true" : "false") << std::endl;

    Triangle t25(Point(0, 0), Point(6, 0), Point(3, 5));
    std::cout << "Autre triangle isocèle, obtenu = "
        << (t25.isIsoceles() ? "true" : "false") << std::endl;

    std::cout << "\n--- Test inscribedCircle() ---" << std::endl;
    Triangle t26(Point(0, 0), Point(10, 0), Point(0, 10));
    Circle circ_in = t26.inscribedCircle();
    std::cout << "Cercle inscrit, rayon = " << circ_in.radius << std::endl;
    circ_in.draw();

    Triangle t27(Point(0, 0), Point(3, 0), Point(0, 4));
    Circle circ_in2 = t27.inscribedCircle();
    std::cout << "Cercle inscrit triangle 3-4-5, rayon = " << circ_in2.radius << std::endl;
    circ_in2.draw();

    std::cout << "\n--- Test circumscribedCircle() ---" << std::endl;
    Triangle t28(Point(0, 0), Point(10, 0), Point(0, 10));
    Circle circ_out = t28.circumscribedCircle();
    std::cout << "Cercle circonscrit, rayon = " << circ_out.radius << std::endl;
    circ_out.draw();

    Triangle t29(Point(0, 0), Point(3, 0), Point(0, 4));
    Circle circ_out2 = t29.circumscribedCircle();
    std::cout << "Cercle circonscrit triangle 3-4-5, rayon = " << circ_out2.radius << std::endl;
    circ_out2.draw();


    // ==========================================
    //              TESTS CERCLE
    // ==========================================
    std::cout << "\n========== TESTS CERCLE ==========" << std::endl;

    std::cout << "\n--- Test circumference() ---" << std::endl;
    Circle c1(5, Point(0, 0));
    std::cout << "Rayon 5, attendu = 31.4, obtenu = " << c1.circumference() << std::endl;

    Circle c2(10, Point(0, 0));
    std::cout << "Rayon 10, attendu = 62.8, obtenu = " << c2.circumference() << std::endl;

    Circle c3(1, Point(0, 0));
    std::cout << "Rayon 1, attendu = 6.28, obtenu = " << c3.circumference() << std::endl;

    std::cout << "\n--- Test area() ---" << std::endl;
    Circle c4(5, Point(0, 0));
    std::cout << "Rayon 5, attendu = 78.5, obtenu = " << c4.area() << std::endl;

    Circle c5(10, Point(0, 0));
    std::cout << "Rayon 10, attendu = 314, obtenu = " << c5.area() << std::endl;

    Circle c5b(1, Point(0, 0));
    std::cout << "Rayon 1, attendu = 3.14, obtenu = " << c5b.area() << std::endl;

    std::cout << "\n--- Test draw() ---" << std::endl;
    Circle c6(50, Point(100, 100));
    std::cout << "Cercle rayon 50 centré en (100, 100)" << std::endl;
    c6.draw();

    Circle c6b(30, Point(200, 200));
    std::cout << "Cercle rayon 30 centré en (200, 200)" << std::endl;
    c6b.draw();

    std::cout << "\n--- Test translate() ---" << std::endl;
    Circle c7(30, Point(0, 0));
    c7.translate(Point(50, 50));
    std::cout << "Translaté de (50, 50)" << std::endl;
    c7.draw();

    Circle c7b(30, Point(100, 100));
    c7b.translate(Point(-50, -50));
    std::cout << "Translaté de (-50, -50)" << std::endl;
    c7b.draw();

    Circle c7c(30, Point(50, 50));
    c7c.translate(Point(0, 0));
    std::cout << "Translaté de (0, 0) (doit pas bouger)" << std::endl;
    c7c.draw();

    std::cout << "\n--- Test resize() ---" << std::endl;
    Circle c8(20, Point(0, 0));
    c8.resize(2);
    std::cout << "Agrandi x2" << std::endl;
    c8.draw();

    Circle c9(20, Point(0, 0));
    c9.resize(0.5);
    std::cout << "Réduit x0.5" << std::endl;
    c9.draw();

    Circle c9b(20, Point(0, 0));
    c9b.resize(1);
    std::cout << "Resize x1 (taille identique)" << std::endl;
    c9b.draw();

    std::cout << "\n--- Test equals() ---" << std::endl;
    Circle c10(5, Point(10, 10));
    Circle c11(5, Point(10, 10));
    std::cout << "Cercles identiques, attendu = true, obtenu = "
        << (c10.equals(c11) ? "true" : "false") << std::endl;

    Circle c12(5, Point(10, 10));
    Circle c13(10, Point(10, 10));
    std::cout << "Rayons différents, attendu = false, obtenu = "
        << (c12.equals(c13) ? "true" : "false") << std::endl;

    Circle c14(5, Point(0, 0));
    Circle c15(5, Point(10, 10));
    std::cout << "Centres différents, attendu = false, obtenu = "
        << (c14.equals(c15) ? "true" : "false") << std::endl;


    // ==========================================
    //              TESTS CARRE
    // ==========================================
    std::cout << "\n========== TESTS CARRE ==========" << std::endl;

    std::cout << "\n--- Test side() ---" << std::endl;
    Square s1(Point(0, 0), Point(10, 10));
    std::cout << "Carré 10x10, obtenu = " << s1.side() << std::endl;

    Square s2(Point(0, 0), Point(5, 5));
    std::cout << "Carré 5x5, obtenu = " << s2.side() << std::endl;

    std::cout << "\n--- Test perimeter() ---" << std::endl;
    Square s3(Point(0, 0), Point(10, 10));
    std::cout << "Carré 10x10, attendu = 40, obtenu = " << s3.perimeter() << std::endl;

    Square s4(Point(0, 0), Point(5, 5));
    std::cout << "Carré 5x5, attendu = 20, obtenu = " << s4.perimeter() << std::endl;

    std::cout << "\n--- Test area() ---" << std::endl;
    Square s5(Point(0, 0), Point(10, 10));
    std::cout << "Carré 10x10, attendu = 100, obtenu = " << s5.area() << std::endl;

    Square s6(Point(0, 0), Point(5, 5));
    std::cout << "Carré 5x5, attendu = 25, obtenu = " << s6.area() << std::endl;

    std::cout << "\n--- Test center() ---" << std::endl;
    Square s7(Point(0, 0), Point(10, 10));
    Point c_sq = s7.center();
    std::cout << "Centre, obtenu = (" << c_sq.x << ", " << c_sq.y << ")" << std::endl;

    Square s8(Point(10, 10), Point(20, 20));
    Point c2_sq = s8.center();
    std::cout << "Centre, obtenu = (" << c2_sq.x << ", " << c2_sq.y << ")" << std::endl;

    std::cout << "\n--- Test draw() ---" << std::endl;
    Square s9(Point(0, 0), Point(50, 50));
    std::cout << "Carré 50x50" << std::endl;
    s9.draw();

    Square s10(Point(100, 100), Point(150, 150));
    std::cout << "Carré décalé" << std::endl;
    s10.draw();

    std::cout << "\n--- Test translate() ---" << std::endl;
    Square s11(Point(0, 0), Point(20, 20));
    s11.translate(Point(50, 50));
    std::cout << "Translaté de (50, 50)" << std::endl;
    s11.draw();

    Square s12(Point(100, 100), Point(120, 120));
    s12.translate(Point(-30, -30));
    std::cout << "Translaté de (-30, -30)" << std::endl;
    s12.draw();

    std::cout << "\n--- Test resize() ---" << std::endl;
    Square s13(Point(0, 0), Point(20, 20));
    s13.resize(2);
    std::cout << "Agrandi x2" << std::endl;
    s13.draw();

    Square s14(Point(0, 0), Point(20, 20));
    s14.resize(0.5);
    std::cout << "Réduit x0.5" << std::endl;
    s14.draw();

    std::cout << "\n--- Test rotate() ---" << std::endl;
    Square s15(Point(0, 0), Point(50, 50));
    s15.rotate(45);
    std::cout << "Tourné de 45 degrés" << std::endl;
    s15.draw();

    Square s16(Point(0, 0), Point(50, 50));
    s16.rotate(90);
    std::cout << "Tourné de 90 degrés" << std::endl;
    s16.draw();

    std::cout << "\n--- Test equals() ---" << std::endl;
    Square s17(Point(0, 0), Point(10, 10));
    Square s18(Point(0, 0), Point(10, 10));
    std::cout << "Carrés identiques, attendu = true, obtenu = "
        << (s17.equals(s18) ? "true" : "false") << std::endl;

    Square s19(Point(0, 0), Point(10, 10));
    Square s20(Point(5, 5), Point(15, 15));
    std::cout << "Carrés différents, attendu = false, obtenu = "
        << (s19.equals(s20) ? "true" : "false") << std::endl;

    std::cout << "\n--- Test inscribedCircle() ---" << std::endl;
    Square s21(Point(0, 0), Point(20, 20));
    Circle circ_sq_in = s21.inscribedCircle();
    std::cout << "Cercle inscrit, rayon = " << circ_sq_in.radius << std::endl;
    circ_sq_in.draw();

    Square s22(Point(0, 0), Point(40, 40));
    Circle circ_sq_in2 = s22.inscribedCircle();
    std::cout << "Cercle inscrit, rayon = " << circ_sq_in2.radius << std::endl;
    circ_sq_in2.draw();

    std::cout << "\n--- Test circumscribedCircle() ---" << std::endl;
    Square s23(Point(0, 0), Point(20, 20));
    Circle circ_sq_out = s23.circumscribedCircle();
    std::cout << "Cercle circonscrit, rayon = " << circ_sq_out.radius << std::endl;
    circ_sq_out.draw();

    Square s24(Point(0, 0), Point(40, 40));
    Circle circ_sq_out2 = s24.circumscribedCircle();
    std::cout << "Cercle circonscrit, rayon = " << circ_sq_out2.radius << std::endl;
    circ_sq_out2.draw();

    return 0;
}

