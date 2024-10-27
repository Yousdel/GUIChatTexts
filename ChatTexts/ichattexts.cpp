#include "ichattexts.h"
#include "ClientUtils.h"



const QString
&IChatTexts::addText(const QString &text,
                     const bool &withNewMsgSeparator)
{
    addText(withNewMsgSeparator &&
            !s.contains(NEW_MSG_SEPARATOR)?
                NEW_MSG_SEPARATOR: "");
    addText(text);
    quitUnnecesaryN();
    return s;
}

const QString
&IChatTexts::quitNewMsgsMark()
{
    if (s.contains(NEW_MSG_SEPARATOR)){
        const QString s1= s.split(NEW_MSG_SEPARATOR).join("");
        s=s1;
    }
    quitUnnecesaryN();
    return s;
}






