#include "CmdAddPointGraph.h"
#include "Document.h"
#include "Logger.h"
#include "MainWindow.h"
#include "QtToString.h"

CmdAddPointGraph::CmdAddPointGraph (MainWindow &mainWindow,
                                    Document &document,
                                    const QString &curveName,
                                    const QPointF &posScreen) :
  CmdAbstract (mainWindow,
               document,
               "Add graph point"),
  m_curveName (curveName),
  m_posScreen (posScreen)
{
  LOG4CPP_INFO_S ((*mainCat)) << "CmdAddPointGraph::CmdAddPointGraph"
                              << " posScreen=" << QPointFToString (posScreen).toLatin1 ().data ();
}

CmdAddPointGraph::~CmdAddPointGraph ()
{
}

void CmdAddPointGraph::cmdRedo ()
{
  LOG4CPP_INFO_S ((*mainCat)) << "CmdAddPointGraph::cmdRedo";

  document().addPointGraph (m_curveName,
                            m_posScreen,
                            m_identifierAdded);
  mainWindow().updateAfterCommand();
}

void CmdAddPointGraph::cmdUndo ()
{
  LOG4CPP_INFO_S ((*mainCat)) << "CmdAddPointGraph::cmdUndo";

  document().removePointGraph (m_identifierAdded);
  mainWindow().updateAfterCommand();
}
