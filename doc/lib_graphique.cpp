/**
 * \page graphic_lib_page Librairies graphiques
 *
 * \section intro_graphic_sec IGraphic
 *
 * Pour utiliser vos librairies graphiques dans l'Arcade, TOUTES vos librairies devront hériter de l'interface IGraphic.
 * Vous pouvez récupérer l'interface dans le [repository de l'Arcade](https://github.com/6im0n/Arcade).
 *
 * \section developper_graphic_sec Développer une librairie graphique
 *
 * Vos librairies devront respecter l'interface IGraphic. Vous devrez donc implémenter les méthodes suivantes:
 * - **isWindowOpen**, cette méthode doit retourner un booléen indiquant si la fenêtre est ouverte ou non.
 * - **closeWindow**, cette méthode doit fermer la fenêtre.
 * - **clearWindow**, cette méthode doit effacer le contenu de la fenêtre.
 * - **getKeyEvent**, cette méthode doit retourner le code de la touche appuyée conformement a la documentation.
 * - **getMousePosition**, cette méthode doit retourner la position de la souris, via une pair d'int (x, y).
 * - **displayWindow**, cette méthode doit afficher la fenêtre.
 * - **displayEntities**, cette méthode doit afficher les entités passées en paramètre, voir \ref entity_page pour plus d'informations sur les entités.
 * - **displayText**, cette méthode doit afficher le texte passé en paramètre, \ref text_page pour plus d'informations sur les textes.
 * - **playSound**, cette méthode doit jouer le son passé en paramètre, voir \ref sound_page pour plus d'information sur les sons.
 */
