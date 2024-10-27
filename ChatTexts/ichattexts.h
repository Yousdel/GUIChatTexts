#ifndef ICHATTEXTS_H
#define ICHATTEXTS_H


#include <QStringList>
#include <QString>

/**
 * @brief Clase que se encarga de manejar
 * una cadena de caracteres a ser interpretada
 * como todo el texto de un chat de textos
 */
class IChatTexts
{
private:
    QString s;

    /**
     * @brief quitUnnecesaryN es para quitar
     * los '\\n' innecesarios
     */
    void quitUnnecesaryN()
    {
        if (s.contains("\n\n"))
            s=s.split("\n\n").join("\n");
    }
public:
    virtual ~IChatTexts(){}

    /**
     * @brief devuelve la cadena s tal cual
     */
    const QString
    &text() {
        quitUnnecesaryN();
        return s; }

    /**
     * @brief agrega el texto y devuelve
     * la cadena s
     */
    const QString
    &addText(const QString &text) {
        s+=text+"\n";
        quitUnnecesaryN();
        return s;
    }

    /**
     * @brief agrega el texto con la posibilidad
     * de anteponerle la marca de Mensaje Nuevo
     * y devuelve la cadena s. Mientras no se invoque
     * quitNewMsgsSeparator(), no se quita la marca
     * de Mensajes nuevos.
     */
    const QString
    &addText(const QString &text,
             const bool &withNewMsgSeparator);

    /**
     * @brief en caso de que exista marca
     * de Mensaje Nuevo, la elimina de la cadena
     * y devuelve la cadena
     */
    const QString
    &quitNewMsgsMark();

    /**
     * @brief devuelve el codigo HTML
     * correspondiente a la cadena s
     */
    virtual const QString
    &getHTML()=0;
};

#endif // ICHATTEXTS_H
