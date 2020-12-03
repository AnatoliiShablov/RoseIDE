#ifndef ASMHIGHLIGHTER_HPP
#define ASMHIGHLIGHTER_HPP

#include <QDebug>
#include <QSyntaxHighlighter>

class ASMHighlighter : public QSyntaxHighlighter {
public:
  Q_OBJECT

public:
  ASMHighlighter(QTextDocument *document) : QSyntaxHighlighter{document} {}

protected:
  void highlightBlock(const QString &text) override {
    QTextCharFormat labelFormat;
    labelFormat.setForeground(Qt::yellow);

    QTextCharFormat registerFormat;
    registerFormat.setForeground(Qt::blue);

    QStringList registers{"eax", "esp"};

    TextType currentType{TextType::Code};

    for (int i = 0; i < text.length(); ++i) {
      if (text.at(i) == '\r' || text.at(i) == '\n') {
        currentType = TextType::Code;
      } else if (currentType == TextType::Code) {
        if (text.at(i) == ';') {
          currentType = TextType::Comment;
        } else if (text.at(i) == '\"' || text.at(i) == '\'') {
          currentType = TextType::String;
        } else if (text.at(i).isLetter()) {
          int j = i + 1;
          while (j < text.length() && text.at(j).isLetterOrNumber()) {
            ++j;
          }
          if (registers.contains(text.mid(i, j - i))) {
            qDebug() << "Register: " << i << j;
            setFormat(i, j, registerFormat);
          } else {
            if (j < text.length() && text.at(j) == ":") {
              ++j;
            }
            qDebug() << "Label: " << i << j;
            setFormat(i, j, labelFormat);
          }
          i = j - 1;
        }
      } else if (currentType == TextType::String) {
        if (text.at(i) == '\"' || text.at(i) == '\'') {
          currentType = TextType::Code;
        }
      }
    }
  }

private:
  enum class TextType { Code, Comment, String };
};

#endif // ASMHIGHLIGHTER_HPP
