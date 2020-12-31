#include "connections_widget.hpp"
#include "project_area.hpp"

ConnectionsWidget::ConnectionsWidget(ProjectArea* projectArea):
    wxWindow(projectArea, wxID_ANY),
    projectArea(projectArea)
{
    this->SetSize(this->projectArea->GetSize());
}

void ConnectionsWidget::paintEvent(wxPaintEvent & evt)
{
    wxPaintDC dc(this);
    wxSize size = this->GetSize();

    // dc.SetPen(*wxBLACK_PEN);
    // dc.SetBrush(wxBrush(wxColor(200, 200, 200)));
    // dc.DrawRectangle(wxRect(0, 0, size.x, size.y));

}

BEGIN_EVENT_TABLE(ConnectionsWidget, wxWindow)
    EVT_PAINT(ConnectionsWidget::paintEvent)
END_EVENT_TABLE()