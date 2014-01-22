#include <QObject>
#include <QByteArray>
#include <QString>

#include "markdown.h"
#include "markdownreader.h"

#include "scribusstructs.h"

QString FileFormatName()
{
    return QObject::tr("Markdown Files");
}

QStringList FileExtensions()
{
    return QStringList("md");
}

void GetText(QString filename, QString encoding, bool textOnly, gtWriter *writer)
{
	MarkdownGetText* markdownGetText = new MarkdownGetText(filename, encoding, textOnly, writer);
	delete markdownGetText;
}

/*
void GetText2(QString filename, QString encoding, bool textOnly, PageItem *textItem)
{
	MarkdownGetText* markdownGetText = new MarkdownGetText(filename, encoding, textItem, textOnly);
	delete markdownGetText;
}
*/

MarkdownGetText::MarkdownGetText(const QString filename, const QString encoding, bool textOnly, gtWriter *writer)
{
	this->filename = filename;
	this->encoding = encoding;
	this->writer = writer;
	this->textOnly = textOnly;
	loadText();
}

/**
 * inactive for now. it's a try to use GetText2 defined for the xtgim loader
 */
MarkdownGetText::MarkdownGetText(const QString filename, const QString encoding, PageItem *textItem, bool textOnly)
{
	this->filename = filename;
	this->encoding = encoding;
	this->textItem = textItem;
	this->textOnly = textOnly;
	// loadText(); TODO: does not work yet
}

void MarkdownGetText::write()
{
}

void MarkdownGetText::loadText()
{
    MarkdownReader* handler = new MarkdownReader(writer, encoding, textOnly);
    // MarkdownReader* handler = new MarkdownReader(textItem, encoding, textOnly);
    handler->parse(filename);
    delete handler;
}

MarkdownGetText::~MarkdownGetText()
{

}
