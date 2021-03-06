#ifndef DOCUMENT_MODEL_CURVE_PROPERTIES_H
#define DOCUMENT_MODEL_CURVE_PROPERTIES_H

#include "ColorPalette.h"
#include "DocumentModelAbstractBase.h"
#include "LineStyle.h"
#include "PointStyle.h"
#include <QHash>

typedef QHash<QString, LineStyle> LineStyles;
typedef QHash<QString, PointStyle> PointStyles;

class Document;

/// Model for DlgSettingsCurveProperties and CmdSettingsCurveProperties.
class DocumentModelCurveProperties : public DocumentModelAbstractBase
{
public:
  /// Default constructor.
  DocumentModelCurveProperties();

  /// Initial constructor from Document.
  DocumentModelCurveProperties(const Document &document);

  /// Copy constructor.
  DocumentModelCurveProperties (const DocumentModelCurveProperties &other);

  /// Assignment constructor.
  DocumentModelCurveProperties &operator=(const DocumentModelCurveProperties &other);
  
  /// Get method for line color in specified curve.
  ColorPalette lineColor (const QString &curveName) const;

  /// Get method for connect as method for lines in specified curve.
  CurveConnectAs lineConnectAs (const QString &curveName) const;

  /// Get method for copying all line styles in one step.
  const LineStyles &lineStyles () const;

  /// Get method for line width in specified curve.
  double lineWidth (const QString &curveName) const;

  /// Get method for curve point color in specified curve.
  ColorPalette pointColor (const QString &curveName) const;

  /// Get method for curve point is circle in specified curve.
  bool pointIsCircle (const QString &curveName) const;

  /// Get method for curve point line width.
  double pointLineWidth (const QString &curveName) const;

  /// Get method for curve point polygon in specified curve.
  QPolygonF pointPolygon (const QString &curveName) const;

  /// Get method for curve point radius.
  int pointRadius (const QString &curveName) const;

  /// Get method for curve point shape.
  PointShape pointShape(const QString &curveName) const;

  /// Get method for copying all point styles in one step.
  const PointStyles &pointStyles () const;

  virtual void saveModel(QXmlStreamWriter &stream) const;

  /// Set method for line color in specified curve.
  void setLineColor (const QString &curveName,
                     ColorPalette lineColor);

  /// Set method for connect as method for lines in specified curve.
  void setLineConnectAs (const QString &curveName,
                         CurveConnectAs curveConnectAs);

  /// Set method for line width in specified curve.
  void setLineWidth (const QString &curveName,
                     int width);

  /// Set method curve point color in specified curve.
  void setPointColor (const QString &curveName,
                      ColorPalette curveColor);

  /// Set method for curve point is circle in specified curve.
  void setPointIsCircle (const QString &curveName,
                         bool pointIsCircle);

  /// Set method for curve point perimeter line width.
  void setPointLineWidth (const QString &curveName,
                          double width);

  /// Set method for curve point radius.
  void setPointRadius (const QString &curveName,
                       int radius);

  /// Set method for curve point shape in specified curve.
  void setPointShape (const QString &curveName,
                      PointShape shape);

private:

  LineStyles m_lineStyles;
  PointStyles m_pointStyles;
};

#endif // DOCUMENT_MODEL_CURVE_PROPERTIES_H
