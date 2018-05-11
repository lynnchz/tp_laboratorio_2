#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {
    char nombre[21];
    int edad;
    int dni;
    int estado;
}ePersona;

/** \brief Obtiene el primer indice libre del array.
 * \param  lista el array se pasa como parametro.
 * \return el primer indice disponible.
 */
int obtEspacioL(ePersona pers[],int cantidad);
/**\brief Recibe la estructura, ejecuta buscarXdni, si el dni existe lo muestra y pide confirmar la baja.
 * \param recibe la estructura lista.
 * \return void muestra el dni buscado para eliminar y lo elimina si el usuario asi lo quiere.
 */
void BorrarP(ePersona pers[],int cantidad);
/** \brief Busca el dni y consigue el indice correspondiente.
 * \param  lista el array y lo pasa como parametro.
 * \return el indice en donde se encuentra el elemento que coincide con el parametro dni.
 */
int buscarXdni(ePersona pers[],int cantidad,int dni);
/** \brief Inicializa el estado de la persona
* \param Le asigna valor 0 al estado
* \return void guarda un registro o avisa falta de espacio.
*/
void inicializarEstadoPersona(ePersona pers[],int cantidad);
int funcionMenu();
/** \brief Se ejecuta obtEspacioL, si hay espacio toma los datos y los guarda sino avisa que falta de espacio.
* \param recibe la estructura lista.
* \return void guarda un registro o avisa falta de espacio.
*/
void AgregarP(ePersona pers[], int cantidad);
/** \brief Muestra a las personas
 * \param muestra nombre dni y edad
 * \return void muestra el listado de personas
 */
void mostrarPersona(ePersona pers);
/** \brief Recibe la estructura, la ordena y la muestra en pantalla.
 * \param recibe la estructura lista.
 * \return void muestra y guarda la estructura ordenada.
 */
void ordenarPersonas(ePersona pers[],int cantidad);

#endif // FUNCIONES_H_INCLUDED
