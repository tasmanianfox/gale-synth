#include "new_connection_widget.hpp"
#include "project_area.hpp"

NewConnectionWidget::NewConnectionWidget(ProjectArea *projectArea) :
    wxWindow(projectArea, wxID_ANY),
    projectArea(projectArea),
    penNewLine(wxPen()),
    clickedPort(nullptr)
{
    this->SetSize(this->projectArea->GetSize());

    this->penNewLine.SetColour(255, 0, 0);
    this->penNewLine.SetWidth(3);
    this->penNewLine.SetStyle(wxPENSTYLE_SOLID);
}

void NewConnectionWidget::paintEvent(wxPaintEvent & evt)
{
    if (this->clickedPort == nullptr)
    {
        return;
    }

    wxPoint posStart =  this->clickedPort->getContainer()->GetPosition() + 
        this->clickedPort->GetPosition() +
        this->clickedPort->getPinCenter();
    wxPoint posEnd = wxGetMousePosition() - GetScreenPosition();
    wxPaintDC dc(this);
	dc.SetPen(this->penNewLine);
    dc.DrawLine(posStart, posEnd);
}

void NewConnectionWidget::setClickedPort(NodePortWidget* widget)
{
    this->clickedPort = widget;
}

NodePortWidget* NewConnectionWidget::getClickedPort()
{
    return this->clickedPort;
}

BEGIN_EVENT_TABLE(NewConnectionWidget, wxWindow)
    EVT_PAINT(NewConnectionWidget::paintEvent)
END_EVENT_TABLE()