#ifndef EXPORT_TO_FILE_H
#define EXPORT_TO_FILE_H

class Document;
class DocumentModelExport;
class QTextStream;

/// Strategy class for exporting to a file. This strategy is external to the Document class so that class is simpler.
class ExportToFile
{
public:
  /// Single constructor.
  ExportToFile();

  /// Export Document points according to the settings. The DocumentModelExport inside the Document is ignored so
  /// DlgSettingsExport can supply its own DocumentModelExport when previewing what would be exported.
  void exportToFile (const DocumentModelExport &modelExport,
                     const Document &document,
                     QTextStream &str) const;
};

#endif // EXPORT_TO_FILE_H
