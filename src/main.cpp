#include <sstream>
#include <list>
#include <algorithm>
#include <image.hpp>
#include <ligne.hpp>
#include <cercle.hpp>
#include <condition.hpp>
#include <estPetite.hpp>
#include <estUn.hpp>
#include <et.hpp>
#include <non.hpp>
#include <filtrage.hpp>

using namespace std;
using namespace figure;

/**
 * Un foncteur du conteneur de figures
 */
extern void affiche(const Figure *f);


static void testPoint();

static void testLigne();

static void testCercle();

static void testImageAllocStatique();

static void testCopy();

static void testImageAllocDynamique();

static void testCreerFigures();

static void testCompterSupprimerSi();

static void testCompterSupprimerSiBis();

static list<const Figure *> *testCompterSupprimerSiBUG();

static list<const Figure *> *testCompterSupprimerSiNOBUG();

std::vector<Condition *> conditionsCheck(list<const Figure *> figures);

void addDataToListNoPointer(list<const Figure *> figures);

/**
 * Un foncteur du conteneur de figures
 */
void affiche(const Figure *f) {
    f->afficher(cout);
    cout << endl;
}

/**
 * Conversion d'un entier en un objet string
 */
string intToString(int n) {
    /**
     * cr?er un flux de sort
     */
    ostringstream os;
    /**
     * ?crire un nombre dans le flux
     */
    os << n;
    /**
     * r?cup?rer une cha?ne de caract?res
     */
    return os.str();
}

void testPoint() {
    Point x;
    Point y(10, 20);
    Point z = Point(y);

    cout << x << y << z << endl;
    z = x + y;
    cout << z << endl;
    z += y;
    cout << z << endl;
    z = x;
    cout << z << endl;
}

void testLigne() {
    Ligne l1 = Ligne(Point(10, 20), Point(16, 30));
    l1.dessiner(cout);
    cout << "Translation(5,8)" << endl;
    l1.deplacer(Point(5, 8));
    l1.dessiner(cout);
    cout << l1 << endl;
}

void testCercle() {
    Cercle c1 = Cercle(Point(10, 20), 22);
    c1.dessiner();
    cout << "Translation(5,8)" << endl;
    c1.deplacer(Point(5, 8));
    c1.dessiner();
    cout << c1 << endl;
}

void testImageAllocStatique() {
    auto l1 = Ligne(Point(10, 20), Point(16, 30));
    auto c1 = Cercle(Point(10, 20), 22);

    auto i1 = Image();
    cout << "image no 1 = ligne no 1 + cercle n? 1" << endl;
    i1.ajouter(l1);
    i1.ajouter(c1);
    i1.dessiner();
    cout << i1 << endl;

    cout << "l1 / Translation(40,50)" << endl;
    l1.deplacer(Point(40, 50));
    i1.dessiner();

    cout << "image no 1 += image no 1" << endl;
    i1.ajouter(i1);
    i1.dessiner();

    cout << "c1 : Translation(11,13)" << endl;
    c1.deplacer(Point(11, 13));
    i1.dessiner();

    cout << "image i1 : Translation(15,40)" << endl;
    i1.deplacer(Point(15, 40));
    i1.dessiner();

    auto i2 = Image();
    cout << "image no 2 = image no 1 + ligne no 1" << endl;
    i2.ajouter(i1);
    i2.ajouter(l1);
    i2.dessiner();
    cout << "image i2 : Translation(150,400)" << endl;
    i2.deplacer(Point(150, 400));
    i2.dessiner();

    auto i3 = Image();
    cout << "image no 2 = image no 1 + image no 2" << endl;
    i3.ajouter(i1);
    i3.ajouter(i2);
    i3.dessiner();
    cout << i3 << endl;
}

void testCopy() {
    auto c1 = std::shared_ptr<Cercle>(new Cercle(Point(10, 20), 2));
    auto fc1 = c1->copy();
    cout << "c1 : " << *c1 << endl;
    cout << "copie de c1 : " << endl;
    /**
    * la figure ne peut ?tre qu'un cercle
    * le static_cast est s?r
    */
    auto c1Copy = fc1;
    cout << *c1Copy << endl;

    auto l1 = std::shared_ptr<Ligne>(new Ligne(Point(10, 20), Point(12, 44)));
    auto fl1 = l1->copy();
    cout << "l1 : " << *l1 << endl;
    cout << "copie de l1 : " << endl;
    auto l1Copy = fl1;
    cout << *l1Copy << endl;

    auto i1 = std::shared_ptr<Image>(new Image());
    i1->ajouter(*c1);
    i1->ajouter(*l1);
    auto fi1 = i1->copy();
    cout << "i1 : " << *i1 << endl;
    cout << "i1Copy copie de i1 : " << endl;
    auto i1Copy = fi1;
    cout << *i1Copy << endl;

    auto i2 = std::shared_ptr<Image>(new Image());
    i2->ajouter(*c1);
    i2->ajouter(*i1);
    auto fi2 = i2->copy();
    cout << "i2 : " << *i2 << endl;
    cout << "i2Copy copie de i2 : " << endl;
    auto i2Copy = fi2;
    cout << *i2Copy << endl;

    auto i3 = std::shared_ptr<Image>(new Image());;
    i3->ajouter(*i1);
    i3->ajouter(*c1);
    i3->ajouter(*i2);
    i3->ajouter(*l1);
    auto fi3 = i3->copy();
    cout << "i3 : " << *i3 << endl;
    cout << "i3Copy copie de i3 : " << endl;
    auto i3Copy = fi3;
    cout << *i3Copy << endl;

    /**
    * test du constructeur de copie de la classe Image
    */
    auto i4 = std::shared_ptr<Image>(new Image(*i3.get()));
    cout << "Contructeur de copie : i4 copie de i3" << endl;
    cout << *i4 << endl;

//    delete c1;
//    delete fc1; // ou delete c1Copy
//    delete l1;
//    delete l1Copy; // ou delete fl1
//    delete i1;
//    delete i1Copy; // ou delete fi1
//    delete i2;
//    delete fi2;  // ou delete i2Copy
//    delete i3;
//    delete i3Copy;  // ou delete fi3

    cout << *i4 << endl;
//    delete i4;
}

void testImageAllocDynamique() {
    auto *l1 = new Ligne(Point(10, 20), Point(16, 30));
    auto *c1 = new Cercle(Point(10, 20), 22);

    auto *i1 = new Image();
    cout << "image no 1 = ligne no 1 + cercle n? 1" << endl;
    i1->ajouter(*l1);
    i1->ajouter(*c1);
    i1->dessiner();
    cout << *i1 << endl;

    cout << "l1 / Translation(40,50)" << endl;
    l1->deplacer(Point(40, 50));
    i1->dessiner();

    cout << "image no 1 += image no 1" << endl;
    i1->ajouter(*i1);
    i1->dessiner();

    cout << "c1 : Translation(11,13)" << endl;
    c1->deplacer(Point(11, 13));
    i1->dessiner();

    cout << "image i1 : Translation(15,40)" << endl;
    i1->deplacer(Point(15, 40));
    i1->dessiner();

    auto *i2 = new Image();
    cout << "image no 2 = image no 1 + ligne no 1" << endl;
    i2->ajouter(*i1);
    i2->ajouter(*l1);
    i2->dessiner();
    cout << "image i2 : Translation(150,400)" << endl;
    i2->deplacer(Point(150, 400));
    i2->dessiner();

    auto *i3 = new Image();
    cout << "image no 2 = image no 1 + iamge no 2" << endl;
    i3->ajouter(*i1);
    i3->ajouter(*i2);
    i3->dessiner();
    cout << *i3 << endl;

    delete c1;
    delete l1;
    delete i1;
    delete i2;
    delete i3;
}

/**
* Uilisation de la classe list de la STL
*/
void testCreerFigures() {
    int nb;
    cout << "nombre de figures : ";
    cin >> nb;

    auto figures = Filtrage::creerFigures(nb);
    figures.push_back(new Cercle(Point(1000, 2000), 200));
    figures.push_back(new Cercle(Point(10, 20), 9));
    figures.push_back(new Cercle(Point(10, 20), 15));
    figures.push_back(new Ligne(Point(10, 20), Point(12, 44)));
    figures.push_back(new Ligne(Point(6, 7), Point(1, 21)));

    auto *i1 = new Image();
    i1->ajouter(*new Cercle(Point(8, 2), 1));
    i1->ajouter(*new Ligne(Point(5, 11), Point(9, 11)));
    figures.push_back(i1);

    figures.push_back(new Cercle(Point(10, 20), 150));

    auto *i2 = new Image();
    i2->ajouter(*new Cercle(Point(1, 6), 4));
    i2->ajouter(*new Cercle(Point(3, 11), 20));
    i2->ajouter(*i1);
    figures.push_back(i2);

    auto *i3 = new Image();
    i3->ajouter(*new Cercle(Point(13, 32), 21));
    i3->ajouter(*new Cercle(Point(27, 12), 7));
    i3->ajouter(*i2);
    i3->ajouter(*new Ligne(Point(5, 11), Point(9, 11)));
    figures.push_back(i3);

    /**
    * LE CODE SUIVANTE PLANTE!
    * on lib?re une image de la liste en dehors de la gestion m?moire d?di?e ? liste
    *
    cout << "
    suppression de l'image i1" << endl;
    delete i1;
    for_each(figures.begin(), figures.end(), affiche);
    */

    /**
    * FOREACH ITERATORS
    list<Figure *>::const_iterator it (figures.begin());
    list<Figure *>::const_iterator end (figures.end());
    for( ; it != end; ++it)
    {
    cout << (**it) << endl;
                                                                                           }
    */

    /**
    *  AVEC LE FONCTEUR affiche
    */
    for_each(figures.begin(), figures.end(), affiche);

    vector<Condition *> conditions = {
        new EstPetite(300),
        new EstUn(&Cercle::temoin),
        new EstUn(&Ligne::temoin),
        new EstUn(&Image::temoin),
        new Non(new EstUn(&Cercle::temoin)),
        new Non(new EstUn(&Ligne::temoin)),
        new Et(new EstUn(&Cercle::temoin), new EstPetite(300))
    };

    for (auto cond:conditions) {
        int n = Filtrage::compterSi(figures, cond, true);
        cout << cond->toString() << " : " << Filtrage::compterSi(figures, cond, true) << "V + ";
        cout << figures.size() - n << "F" << endl;
    }

    cout << endl << "SUPPRESSION supperficielle des lignes" << endl;
    Filtrage::supprimerSi(figures, conditions[2]);
    for_each(figures.begin(), figures.end(), affiche);

    cout << endl << "SUPPRESSION profonde des lignes" << endl;
    Filtrage::supprimerSiProfond(figures, conditions[2]);
    for_each(figures.begin(), figures.end(), affiche);

    /**
    * CTOR de copie profonde des listes de la STL
    */
    auto copy = list<const Figure *>(figures);
    cout << "copie de la liste originale : " << endl;
    for_each(copy.begin(), copy.end(), affiche);


    cout << "destruction de liste originale : " << endl;
    figures.clear();
    if (figures.empty()) {
        cout << "La liste originale est vide." << endl;
    }
    cout << "Affichage de la liste originale : " << endl;
    for_each(figures.begin(), figures.end(), affiche);
    cout << "Aucune modification de la copie profonde de la liste originale : " << endl;
    for_each(copy.begin(), copy.end(), affiche);
}

void testCompterSupprimerSi() {
    auto figures = list<const Figure *>();
    cout << "test///////////////////" << endl;
    addDataToListNoPointer(figures);
    cout << "test///////////////////" << endl;

    for_each(figures.begin(), figures.end(), affiche);

    vector<Condition *> conditions = conditionsCheck(figures);

    cout << endl << "SUPPRESSION superficielle des cercles" << endl;
    if (Filtrage::supprimerSi(figures, conditions[1])) {
        cout << "Supprimer sous condition SUCCES" << endl;
        for_each(figures.begin(), figures.end(), affiche);
    }

    cout << endl << "SUPPRESSION profonde des cercles" << endl;
    if (Filtrage::supprimerSiProfond(figures, conditions[1])) {
        cout << "Supprimer sous condition SUCCES" << endl;
        for_each(figures.begin(), figures.end(), affiche);
    }
}

void testCompterSupprimerSiBis() {
    auto figures = list<const Figure *>();

    addDataToListNoPointer(figures);

    for_each(figures.begin(), figures.end(), affiche);

    vector<Condition *> conditions = conditionsCheck(figures);

    cout << endl << "SUPPRESSION superficielle des cercles" << endl;
    if (Filtrage::supprimerSiBis(figures, conditions[1])) {
        cout << "Supprimer sous condition SUCCES" << endl;
        for_each(figures.begin(), figures.end(), affiche);
    }

    cout << endl << "SUPPRESSION profonde des cercles" << endl;
    if (Filtrage::supprimerSiProfondBis(figures, conditions[1])) {
        cout << "Supprimer sous condition SUCCES" << endl;
        for_each(figures.begin(), figures.end(), affiche);
    }
}

void addDataToListNoPointer(list<const Figure *> figures) {
    auto c1 = Cercle(Point(10, 20), 2);
    auto c2 = Cercle(Point(10, 20), 9);
    auto c3 = Cercle(Point(10, 20), 15);
    figures.push_back(&c1);
    figures.push_back(&c2);
    figures.push_back(&c3);

    auto l1 = Ligne(Point(10, 20), Point(12, 44));
    auto l2 = Ligne(Point(6, 7), Point(1, 21));
    figures.push_back(&l1);
    figures.push_back(&l2);

    auto i1 = Image();
    i1.ajouter(c1);
    i1.ajouter(l1);
    figures.push_back(&i1);

    auto c4 = Cercle(Point(10, 20), 150);
    figures.push_back(&c4);

    auto i2 = Image();
    i2.ajouter(c2);
    i2.ajouter(c4);
    i2.ajouter(i1);
    figures.push_back(&i2);

    auto i3 = Image();
    i3.ajouter(c3);
    i3.ajouter(c4);
    i3.ajouter(i2);
    i3.ajouter(l2);
    figures.push_back(&i3);
}

std::vector<Condition *> conditionsCheck(list<const Figure *> figures) {
    vector<Condition *> conditions;
    conditions.push_back(new EstPetite(300));
    conditions.push_back(new EstUn(&Cercle::temoin));
    conditions.push_back(new EstUn(&Image::temoin));
    conditions.push_back(new Non(new EstUn(&Cercle::temoin)));
    conditions.push_back(new Non(new EstUn(&Ligne::temoin)));
    conditions.push_back(new Et(new EstUn(&Cercle::temoin), new EstPetite(300)));

    for (auto cond:conditions) {
        int n = Filtrage::compterSi(figures, cond, true);
        cout << cond->toString() << " : " << Filtrage::compterSi(figures, cond, true) << "V + ";
        cout << figures.size() - n << "F" << endl;
    }
    return conditions;
}


/**
* PLANTAGE d? ? une m?connaissance de la gestion m?moire!
* Tout se passe convenablement dans le contexte de la fonction : les variables locales y sont disponibles.
* La liste contient des variables locales qui ne sont plus disponibles
* dans le contexte de l'appelant.
* Or cette liste est retourn?e de mani?re illogique dans le contexte de l'appelant.
* Le plantage a lieu dans le contexte de l'appelant.
* A l'ex?cution le message PURE VIRTUAL METHOD CALLED est affich?.
*/
list<const Figure *> *testCompterSupprimerSiBUG() {
    auto *figures = new list<const Figure *>();

    addDataToListNoPointer(*figures);

    for_each(figures->begin(), figures->end(), affiche);

    vector<Condition *> conditions = conditionsCheck(*figures);

    cout << endl << "SUPPRESSION supperficielle des cercles" << endl;
    Filtrage::supprimerSi(*figures, conditions[1]);
    for_each(figures->begin(), figures->end(), affiche);

    cout << endl << "SUPPRESSION profonde des cercles" << endl;
    Filtrage::supprimerSiProfond(*figures, conditions[1]);
    for_each(figures->begin(), figures->end(), affiche);

    return figures;
}


list<const Figure *> *testCompterSupprimerSiNOBUG() {
    auto *figures = new list<const Figure *>();

    auto *c1 = new Cercle(Point(10, 20), 2);
    auto *c2 = new Cercle(Point(10, 20), 9);
    auto *c3 = new Cercle(Point(10, 20), 15);
    figures->push_back(c1);
    figures->push_back(c2);
    figures->push_back(c3);

    auto *l1 = new Ligne(Point(10, 20), Point(12, 44));
    auto *l2 = new Ligne(Point(6, 7), Point(1, 21));
    figures->push_back(l1);
    figures->push_back(l2);

    auto *i1 = new Image();
    i1->ajouter(*c1);
    i1->ajouter(*l1);
    figures->push_back(i1);

    auto *c4 = new Cercle(Point(10, 20), 150);
    figures->push_back(c4);

    auto *i2 = new Image();
    i2->ajouter(*c2);
    i2->ajouter(*c4);
    i2->ajouter(*i1);
    figures->push_back(i2);

    auto *i3 = new Image();
    i3->ajouter(*c3);
    i3->ajouter(*c4);
    i3->ajouter(*i2);
    i3->ajouter(*l2);
    figures->push_back(i3);

    for_each(figures->begin(), figures->end(), affiche);

    vector<Condition *> conditions = conditionsCheck(*figures);

    cout << endl << "SUPPRESSION supperficielle des cercles" << endl;
    Filtrage::supprimerSi(*figures, conditions[1]);
    for_each(figures->begin(), figures->end(), affiche);

    cout << endl << "SUPPRESSION profonde des cercles" << endl;
    Filtrage::supprimerSiProfond(*figures, conditions[1]);
    for_each(figures->begin(), figures->end(), affiche);

    return figures;
}


int main() {
    int choix;
    char c;

    do {
        do {
            cout << "1 : Point " << endl;
            cout << "2 : Ligne " << endl;
            cout << "3 : Cercle " << endl;
            cout << "4 : Figures allouees statiquement " << endl;
            cout << "5 : Copies virtuelles dynamiques de figures " << endl;
            cout << "6 : Figures allouees dynamiquement " << endl;
            cout << "7 : Generation aleatoire de figures " << endl;
            cout << "8 : Filtrage selon une condition : comptage et suppression superfielle " << endl;
            cout << "9 : Filtrage selon une condition : comptage et suppression profonde " << endl;
            cout << "10 : Filtrage BUG " << endl;
            cout << "11 : Filtrage NOBUG " << endl;
            cout << "Votre choix : ";
            cin >> choix;
        } while (choix < 1 || choix > 11);

        switch (choix) {
            case 1 :
                testPoint();
                break;
            case 2 :
                testLigne();
                break;
            case 3 :
                testCercle();
                break;
            case 4 :
                testImageAllocStatique();
                ///// Segfault la sortie , pas de raison
                break;
            case 5 :
                testCopy();
                ///// Segfault la sortie , pas de raison
                break;
            case 6 :
                testImageAllocDynamique();
                ///// Segfault la sortie , pas de raison
                break;
            case 7 :
                testCreerFigures();
                break;
            case 8 :
                testCompterSupprimerSi();
                break;
            case 9 :
                testCompterSupprimerSiBis();
                break;
            case 10 :
                /**
                 * PLANTE car la liste retourn?e a contenu des variables locales de la pile
                 * qui ont ?t? lib?r?es automatiquement
                 */
            {
                list<const Figure *> *figures = testCompterSupprimerSiBUG();
                for_each(figures->begin(), figures->end(), affiche);
            }
                break;
            case 11 :
                /**
                 * NE PLANTE PAS car la liste retourn?e contient des variables allou?es dynamiquement
                 */
            {
                list<const Figure *> *figures = testCompterSupprimerSiNOBUG();
                for_each(figures->begin(), figures->end(), affiche);
            }
                break;
            default :
                cout << "Choix invalide " << endl;
                break;

        }
        cout << "Encore? : y/n";
        cin >> c;
    } while (c != 'N' && c != 'n');


    return 0;
}
