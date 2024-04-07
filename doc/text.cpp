/**
 * \page text_page Interface IText
 * 
 * \section intro_text_sec Introduction
 * L'Interfaces IText permet de définir les textes du jeu afin que le jeu puisse communiquer avec la lib graphiques facilement.
 * Tous les textes doivent hériter de IText.
 * 
 * \section config_text_sec Configurer un texte
 * Pour configurer un texte, vous devez implémenter les méthodes suivantes:
 * - **setFontPath**, cette méthode doit définir le chemin de la police du texte.
 * - **setText**, cette méthode doit définir le texte à écrire.
 * - **setColor**, cette méthode doit définir la couleur du texte, conformément a l'interface IColor \ref color_page.
 * - **setPos**, cette méthode doit définir la position du texte.
 * - **setSize**, cette méthode doit définir la taille du texte.
 * - **setRotation**, cette méthode doit définir la rotation du texte.
 * - **getFontPath**, cette méthode doit retourner le chemin de la police du texte.
 * - **getText**, cette méthode doit retourner le texte à écrire.
 * - **getColor**, cette méthode doit retourner la couleur du texte.
 * - **getPos**, cette méthode doit retourner la position du texte.
 * - **getSize**, cette méthode doit retourner la taille du texte.
 * - **getRotation**, cette méthode doit retourner la rotation du texte.
 */
