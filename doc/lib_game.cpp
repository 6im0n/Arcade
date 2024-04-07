/**
 * \page game_lib_page Librairies de jeu
 *
 * \section intro_game_sec IGame
 *
 * Pour utiliser vos librairies de jeu dans l'Arcade, TOUTES vos librairies devront hériter de l'interface IGame.
 * Vous pouvez récupérer l'interface dans le [repository de l'Arcade](https://github.com/6im0n/Arcade) dans le dossier Interfaces.
 *
 * \section developper_game_sec Développer une librairie de jeu
 *
 * Vos librairies devront respecter l'interface IGraphic. Vous devrez donc implémenter les méthodes suivantes:
 * - **startGame**, cette méthode doit démarrer le jeu.
 * - **stopGame**, cette méthode doit arrêter le jeu.
 * - **getScore**, cette méthode doit retourner le score du joueur.
 * - **simulate**, cette méthode doit simuler un frame du jeu.
 * - **catchKeyEvent**, cette méthode doit gérer les évènements clavier.
 * - **catchMousePosition**, cette méthode doit gérer les évènements souris.
 * - **setUserName**, cette méthode doit définir le nom du joueur.
 * - **getUserName**, cette méthode doit retourner le nom du joueur.
 * - **getEntities**, cette méthode doit retourner les entités du jeu à afficher, voir \ref entity_page pour plus d'information sur les entités.
 * - **getTexts**, cette méthode doit retourner les textes du jeu à afficher, voir \ref text_page pour plus d'information sur les textes.
 * - **getSounds**, cette méthode doit retourner les sons du jeu à afficher, voir \ref sound_page pour plus d'information sur les sons.
 */
