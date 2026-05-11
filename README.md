# Projet2Dgeo
Projet C++ pour manipuler des objets géométriques en 2D. On peut créer et tester des tiangles, cercles et carrés avec différentes opérations (calcul d'aire, périmètre, translation, rotation, etc ).

## Installation 

Il faut cloner le repo et compiler :

```bash
git clone https://github.com/shiwaybtc-web/Project2Dgeo.git
cd Project2dgeo
make clean
make
```
Puis il faut lancer le programme :

```bash
./main
```

Une fenêtre CTurtle s'ouvre et affiche les formes dessinées

## Structure

- `include/` - Déclarations des classes (point.hpp, circle.hpp, triangle.hpp, square.hpp)
- `src/` - Implémentations (point.cpp, circle.cpp, etc.)
- `src/shapes/` - Code des formes géométriques
- `main.cpp` - Tests et affichage
- `makefile` - Configuration de compilation

## Les formes

### Triangle

Défini par 3 points. Calcule le périmètre, l'aire, le centre. Il peut être translaté, redimensionné et tourné.

### Cercle 

Défini par un rayon et un centre. Calcule la circonférence, l'aire. Il peut être translaté, redimensionné et tourné.

### Square 

Défini par 2 coins opposés. Calcul le côté, le périmètre, l'aire. Il peut être translaté, redimensionné et tourné.

## Utilisation

```cpp
#include "triangle.hpp"

int main() {
    Triangle t(Point(0, 0), Point(10, 0), Point(5, 10));
    t.display();
    std::cout << "Périmètre: " << t.perimeter() << std::endl;
    t.translate(Point(5, 5));
    t.draw();
    return 0;
}
```
## Équipe

- **Chef de projet** - Alexandre Moussier et Zineb
- **Développeur Triangle** - Younes Ben Yahia
- **Développeur Cercle** - Adam Menacer
- **Développeur Carré** - Catherine Grace Djuichou Fotso


# Travail d'équipe

Chaque développeur travaille sur sa propre branche ( triangle, cercle, square) et fais des push réguliers. Le chef de projet teste et donne un retour.

```bash
# Créer sa branche
git checkout -b triangle

# Développer
# ... modifier src/shapes/triangle.cpp ...

# Commit et push
git add src/shapes/triangle.cpp
git commit -m "Implémentation du constructeur"
git push origin triangle
```

## Licence

MIT license







