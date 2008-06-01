#ifndef SPRINGLOBBY_HEADERGUARD_MAINSINGLEPLAYERTAB_H
#define SPRINGLOBBY_HEADERGUARD_MAINSINGLEPLAYERTAB_H


#include <wx/panel.h>


class Ui;
class wxNotebook;
class wxAuiNotebook;
class wxImageList;
class wxBoxSizer;
class SinglePlayerTab;
class BattleOptionsTab;
class BattleroomMMOptionsTab;


class MainSinglePlayerTab : public wxPanel
{
  public:
    MainSinglePlayerTab( wxWindow* parent, Ui& ui );
    ~MainSinglePlayerTab();

    void UpdateMinimap();
    void OnUnitSyncReloaded();

    void ReloadRestrictions();
    void ReloadMapOptContrls();
    void ReloadModOptContrls();

  protected:

    Ui& m_ui;

    wxBoxSizer* m_main_sizer;
    wxImageList* m_imagelist;
    #ifdef HAVE_WX26
    wxNotebook* m_tabs;
    #else
    wxAuiNotebook* m_tabs;
    #endif

    SinglePlayerTab* m_sp_tab;
    BattleOptionsTab* m_opts_tab;
    BattleroomMMOptionsTab* m_mm_opts_tab;

};


#endif // SPRINGLOBBY_HEADERGUARD_MAINSINGLEPLAYERTAB_H
