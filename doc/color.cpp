/**
 * \page color_page Interface IColor
 * 
 * \section intro_color_sec Introduction
 * L'Interfaces IColor permet de définir les couleurs du jeu afin que le jeu puisse communiquer avec la lib graphiques facilement.
 * Toutes les couleurs doivent hériter de IColor.
 * 
 * \section config_color_sec Configurer une couleur
 * L'interfaces couleur est composé d'un constructeur et de 4 getters:
 * - Le constructeur doit prendre 4 paramètres r (pour le niveau de rouge), g (pour le niveau de vert), b (pour le niveau de bleu), a (pour la transparence).
 * - **getR** doit retourner la valeur de r.
 * - **getG** doit retourner la valeur de g.
 * - **getB** doit retourner la valeur de b.
 * - **getA** doit retourner la valeur de a.
 */