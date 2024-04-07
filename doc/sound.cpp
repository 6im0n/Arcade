/**
 * \page sound_page Interface ISound
 * 
 * \section intro_sound_sec Introduction
 * L'Interfaces ISound permet de définir les sons du jeu afin que le jeu puisse communiquer avec la lib graphiques facilement.
 * Tous les sons doivent hériter de ISound.
 * 
 * \section config_sound_sec Configurer un son
 * Pour configurer un son, vous devez implémenter les méthodes suivantes:
 * - **setPathSound**, cette méthode doit définir le chemin du son.
 * - **setVolume**, cette méthode doit définir le volume du son.
 * - **setStatus**, cette méthode doit définir le status du son via une enum (start, loop, stop, done).
 * - **getPathSound**, cette méthode doit retourner le chemin du son.
 * - **getVolume**, cette méthode doit retourner le volume du son.
 * - **getStatus**, cette méthode doit retourner le status du son.
 */