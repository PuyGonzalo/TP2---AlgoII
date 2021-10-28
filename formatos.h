#ifndef FORMATOS_H
#define FORMATOS_H

#ifdef __linux__
#define CLR_SCREEN "clear"
#endif // __linux__

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif // __MINGW32__

#define TAB '\t'
#define FIN_DE_FORMATO "\033[0m"

#define SUBRAYADO "\033[4m"
#define NEGRITA "\033[1m"

#define FONDO_COLOR_VERDE "\033[48;5;22m"
#define FONDO_COLOR_AZUL "\033[48;5;4m"
#define FONDO_COLOR_GRIS "\033[48;5;59m"


#endif // TYPES_H
