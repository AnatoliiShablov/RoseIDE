#ifndef ASMHIGHLIGHTER_HPP
#define ASMHIGHLIGHTER_HPP

#include <QSyntaxHighlighter>

class ASMHighlighter : public QSyntaxHighlighter {
public:
  ASMHighlighter(QTextDocument *document) : QSyntaxHighlighter{document} {}

protected:
  void highlightBlock(const QString &text) override {
    if (text.length() > 10) {
      QTextCharFormat format;
      format.setForeground(Qt::darkBlue);
      format.setBackground(Qt::red);
      setFormat(3, 5, format);
    }
  }
};

#endif // ASMHIGHLIGHTER_HPP
