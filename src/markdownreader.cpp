#include <QString>
#include <QTextCodec> 
#include <QByteArray>
#include <QTextCodec> 

#include "markdownreader.h"
#include "util.h" // for loadRawText

MarkdownReader::MarkdownReader(gtWriter *writer, QString encoding, bool textOnly)
{
    this->writer = writer;
    this->encoding = encoding;
    this->textOnly = textOnly;
}

MarkdownReader::~MarkdownReader()
{
}

void MarkdownReader::parse(QString filename)
{
    QString text;
	QByteArray rawText;
    QTextCodec *codec;
    if (loadRawText(filename, rawText))
    {
        if (textOnly)
        {
            // TODO: not correct: if textOnly it should also parse but only retain the text and not the formatting
            if (encoding.isEmpty())
            {
                codec = QTextCodec::codecForLocale();
            }
            else
            {
                codec = QTextCodec::codecForName(encoding.toLocal8Bit());
            }
            text = codec->toUnicode(rawText);
            writer->appendUnstyled(text);
        } else {
            // QString content = document->toPlainText();
            // QByteArray ba = content.toLatin1();
            // char *content_cstring = strdup((char *)ba.data());

            // char *content_cstring = strdup((char *)rawText.data());

            // QString text = QString::fromUtf8(rawText);

            // TODO: hic sun leones... do the parsing


        }
    }
}
