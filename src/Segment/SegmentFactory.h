#ifndef SEGMENT_FACTORY_H
#define SEGMENT_FACTORY_H

#include <QList>

class DocumentModelSegments;
class QGraphicsScene;
class QImage;
class Segment;

/// Factory class for Segment objects. The input is the filtered image.
class SegmentFactory
{
public:
  /// Single constructor.
  SegmentFactory(QGraphicsScene &scene);

  /// Return segment fill points for all segments, for previewing
  QList<QPoint> fillPoints(const DocumentModelSegments &modelSegments);

  /// Main entry point for creating all Segments for the filtered image.
  void makeSegments (const QImage &imageFiltered,
                     const DocumentModelSegments &modelSegments,
                     QList<Segment*> segments);

private:
  SegmentFactory();

  // Return the number of runs adjacent to the pixels from yStart to yStop (inclusive)
  int adjacentRuns(bool *columnBool, int yStart, int yStop, int height);

  // Find the single segment pointer among the adjacent pixels from yStart-1 to yStop+1
  Segment *adjacentSegment(Segment **lastSegment, int yStart, int yStop, int height);

  // Return the number of segments adjacent to the pixels from yStart to yStop (inclusive)
  int adjacentSegments(Segment **lastSegment, int yStart, int yStop, int height);

  // Process a run of pixels. If there are fewer than two adjacent pixel runs on
  // either side, this run will be added to an existing segment, or the start of
  // a new segment
  void finishRun(bool *lastBool,
                 bool *nextBool,
                 Segment **lastSegment,
                 Segment **currSegment,
                 int x,
                 int yStart,
                 int yStop,
                 int height,
                 const DocumentModelSegments &modelSegments,
                 int* madeLines,
                 QList<Segment*> segments);

  // Initialize one column of boolean flags using the pixels of the specified column
  void loadBool (const Filter &filter,
                 bool *columnBool,
                 const QImage &image,
                 int x);

  // Initialize one column of segment pointers
  void loadSegment (Segment **columnSegment,
                    int height);

  // Identify the runs in a column, and connect them to segments
  void matchRunsToSegments (int x,
                            int height,
                            bool *lastBool,
                            Segment **lastSegment,
                            bool *currBool,
                            Segment **currSegment,
                            bool *nextBool,
                            const DocumentModelSegments &modelSegments,
                            int *madeLines,
                            int *foldedLines,
                            int *shortLine,
                            QList<Segment*> segments);

  // Remove unneeded lines belonging to segments that just finished in the previous column.
  // The results of this function are displayed in the debug spew of makeSegments
  void removeUnneededLines(Segment **lastSegment,
                           Segment **currSegment,
                           int height,
                           int *foldedLines,
                           int *shortLines,
                           const DocumentModelSegments &modelSegments);

  // Scroll the boolean flags of the right column into the left column
  void scrollBool(bool *left,
                  bool *right,
                  int height);

  // Scroll the segment pointers of the right column into the left column
  void scrollSegment(Segment **left,
                     Segment **right,
                     int height);

  QGraphicsScene &m_scene;

  // Segments produced by scanning the image
  QList<Segment*> m_segments;
};

#endif // SEGMENT_FACTORY_H
