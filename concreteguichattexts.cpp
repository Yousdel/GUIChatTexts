#include "concreteguichattexts.h"
#include "ChatTexts/ClientUtils.h"


const QString
ConcreteGUIChatTexts::getHTMLfor(const QString &s)
{
    QString htmlFor;
    if (s.contains(NEW_MSG_TEXT)){
        htmlFor += "<div style =\"color:blue;\"><p align=\"center\"><hr/>";
        htmlFor += s;
        htmlFor += "<hr/></p></div>";
    }
    else{
        if (s.contains(": ")){
            htmlFor += workTextTypeChat(s);
        }
    }
    return htmlFor;
}

const QString
ConcreteGUIChatTexts::workTextTypeChat(const QString &text)
{
    if (text.contains(": ")==0)
        return QString();
    const QString name = text.split(":").at(0),
            restOfMsg= text.section(":", 1,-1),
            s( "<div style=\"color:black;\"><p align=\"left\" ><b>"+name+
               ":</b>"+restOfMsg+"</p>" );
    return s;
}


const QString
&ConcreteGUIChatTexts::getHTML()
{
    const QStringList sN = text().split("\n");
    html.clear();
    bool newMsg=0, firstNewMsg=0;
    for (const QString &ss : sN)
        if (ss.isEmpty()) continue;
        else
        {
            firstNewMsg = !newMsg && ss.contains(NEW_MSG_SEPARATOR);
            newMsg |= ss.contains(NEW_MSG_SEPARATOR);

            if (ss.contains(NEW_MSG_SEPARATOR)==0)
                html += getHTMLfor(ss);
            else {
                if (firstNewMsg)
                    html += getHTMLfor(NEW_MSG_TEXT);
            }
        }
    return html;
}
