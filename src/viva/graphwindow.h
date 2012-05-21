#ifndef __GRAPH_WINDOW_H
#define __GRAPH_WINDOW_H
#include <wx/artprov.h>
#include "basic.h"
#include "graphframe.h"
#include "timesliceframe.h"
#include "VivaGraph.h"

class VivaGraph;

DECLARE_EVENT_TYPE (VivaGraphChanged, -1)
DECLARE_EVENT_TYPE (VivaGraphLayoutUpdated, -1)

class GraphWindow : public wxFrame
{
private:
  VivaGraph *vivagraph;

  wxMenuBar *menubar;
  wxMenu *file;
  wxMenu *edit;
  wxMenu *view;
  wxMenu *help;

private:
  std::map<std::string,wxSlider*> scaleSliders;

protected:
  void OnTimeIntervalMenu (wxCommandEvent& event);
  void OnGraphConfigurationMenu (wxCommandEvent& event);
  void OnUpdateQuality (wxCommandEvent& event);
  void OnQuit(wxCommandEvent& event);
  void OnOpen(wxCommandEvent& event);
  void OnAbout (wxCommandEvent& event);

  void OnScaleSliderChanged (wxScrollEvent& event);

public:
  GraphWindow (wxWindow *parent, VivaGraph *vivagraph);
  ~GraphWindow (void);
  double scaleSliderValue (std::string name);
};

#endif