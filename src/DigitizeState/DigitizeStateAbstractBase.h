#ifndef DIGITIZE_STATE_ABSTRACT_BASE_H
#define DIGITIZE_STATE_ABSTRACT_BASE_H

#include <QPointF>

class DigitizeStateContext;
class QGraphicsScene;
class QImage;
class QTimer;

/// Set of possible states of Digitize toolbar.
enum DigitizeState {
  DIGITIZE_STATE_AXIS,
  DIGITIZE_STATE_CURVE,
  DIGITIZE_STATE_EMPTY,
  DIGITIZE_STATE_POINT_MATCH,
  DIGITIZE_STATE_SCALE,
  DIGITIZE_STATE_SEGMENT,
  DIGITIZE_STATE_SELECT,
  NUM_DIGITIZE_STATES
};

/// Base class for all digitizing states. This serves as an interface to DigitizeStateContext
class DigitizeStateAbstractBase
{
public:
  /// Single constructor.
  DigitizeStateAbstractBase(DigitizeStateContext &context);
  virtual ~DigitizeStateAbstractBase ();

  /// Method that is called at the exact moment a state is entered. Typically called just after end for the previous state
  virtual void begin() = 0;

  /// Reference to the DigitizeStateContext that contains all the DigitizeStateAbstractBase subclasses, without const.
  DigitizeStateContext &context();

  /// Reference to the DigitizeStateContext that contains all the DigitizeStateAbstractBase subclasses, without const.
  const DigitizeStateContext &context() const;

  /// Method that is called at the exact moment a state is exited. Typically called just before begin for the next state
  virtual void end() = 0;

  /// Handle a right click that was intercepted earlier. This is done in the superclass since it works the same in all states.
  void handleContextMenuEvent (const QString &pointIdentifier);

  /// Handle a key press that was intercepted earlier.
  virtual void handleKeyPress (Qt::Key key) = 0;

  /// Handle leave in case an override cursor is in effect from last QDialog, by resetting the override cursor.
  virtual void handleLeave ();

  /// Handle a mouse press that was intercepted earlier.
  virtual void handleMousePress (QPointF pos) = 0;

  /// Handle a mouse release that was intercepted earlier.
  virtual void handleMouseRelease (QPointF pos) = 0;

  /// Handle the command to set the override cursor
  void handleSetOverrideCursor (Qt::CursorShape cursorShape);

  /// Remove the override cursor if it is in use. This is called after a leave event, and prior to displaying a QDialog
  void removeOverrideCursor ();

  /// Update the cursor according to the current state.
  void setCursor();

protected:
  /// Returns the state-specific cursor shape.
  virtual Qt::CursorShape cursorShape () const = 0;

private:
  DigitizeStateAbstractBase();

  DigitizeStateContext &m_context;

  bool m_isOverrideCursor; // Checking QApplication::overrideCursor()==0 is unreliable so this tracks the override cursor state
};

#endif // DIGITIZE_STATE_ABSTRACT_BASE_H
