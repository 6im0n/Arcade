/**
 * \page entity_page Interface IEntity
 * 
 * \section intro_entity_sec Introduction
 * L'Interfaces IEntity permet de définir les entités du jeu afin que le jeu puisse communiquer avec la lib graphiques facilement.
 * Toutes les entités doivent hériter de IEntity.
 * 
 * \section config_entity_sec Configurer une entité
 * Pour configurer une entité, vous devez implémenter les méthodes suivantes:
 * - **setPos**, cette méthode doit définir la position de l'entité (le système de position correspond à un système de cadrillage chaque case fait 29x29 pixels, vous devez renseigné la position en case, par exemple si on set la position a 2, 10 l'entité s'affichera a 58x290 pixels).
 * - **setSize**, cette méthode doit définir la taille de l'entité en pixels.
 * - **setChar**, cette méthode doit définir le caractère de l'entité (utiliser en cas de problèmes avec l'asset ou pour les librairies graphiques ne gérant pas les images).
 * - **setColor**, cette méthode doit définir la couleur de l'entité (on utilise l'interface IColor \ref color_page).
 * - **setPath**, cette méthode doit définir le chemin de l'asset de l'entité.
 * - **setRotation**, cette méthode doit définir la rotation de l'entité.
 * - **getPos**, cette méthode doit retourner la position de l'entité.
 * - **getSize**, cette méthode doit retourner la taille de l'entité.
 * - **getChar**, cette méthode doit retourner le caractère de l'entité.
 * - **getColor**, cette méthode doit retourner la couleur de l'entité.
 * - **getPath**, cette méthode doit retourner le chemin de l'asset de l'entité.
 * - **getRotation**, cette méthode doit retourner la rotation de l'entité.
 */