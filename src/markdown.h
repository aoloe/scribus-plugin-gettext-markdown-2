/*
(c) GPL Ale Rimoldi, 2014
*/
#ifndef MARKDOWNGETTEXT_H
#define MARKDOWNGETTEXT_H

#include "pluginapi.h"
#include "gtwriter.h"

extern "C" PLUGIN_API void GetText(QString filename, QString encoding, bool textOnly, gtWriter *writer);

extern "C" PLUGIN_API QString FileFormatName();

extern "C" PLUGIN_API QStringList FileExtensions();

class QByteArray;

class MarkdownGetText
{
public:
	MarkdownGetText(const QString filename, const QString encoding, bool textOnly, gtWriter *writer);
	~MarkdownGetText();
	void write();
private:
	QString filename;
	QString encoding;
	QString text;
	gtWriter *writer;
	bool textOnly;
	void loadText();
	QString toUnicode(const QByteArray& rawText);
};

#endif // MARKDOWNGETTEXT_H

