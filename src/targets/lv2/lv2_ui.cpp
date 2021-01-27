// #include <math.h>
#include <stdlib.h>

// #include <lv2/lv2plug.in/ns/lv2core/lv2.h>
#include <lv2/lv2plug.in/ns/extensions/ui/ui.h>
#include <lv2/atom/atom.h>
#include <lv2/atom/forge.h>
#include <lv2/atom/util.h>
#include <lv2/core/lv2.h>
#include <lv2/core/lv2_util.h>
#include <lv2/log/log.h>
#include <lv2/log/logger.h>
#include <lv2/midi/midi.h>
#include <lv2/ui/ui.h>
#include <lv2/urid/urid.h>


#include "gui/app.hpp"

#define AMP_URI "https://github.com/tasmanianfox/gale-synth#ExternalUI"

IMPLEMENT_APP_NO_MAIN(App);
IMPLEMENT_WX_THEME_SUPPORT;


// #define DB_CO(g) ((g) > -90.0f ? powf(10.0f, (g) * 0.05f) : 0.0f)

typedef enum {
        AMP_GAIN   = 0,
        AMP_INPUT  = 1,
        AMP_OUTPUT = 2
} PortIndex;

typedef struct {
        const float* gain;
        const float* input;
        float*       output;
} Amp;

static LV2UI_Handle
instantiate(const LV2UI_Descriptor*   descriptor,
            const char*               plugin_uri,
            const char*               bundle_path,
            LV2UI_Write_Function      write_function,
            LV2UI_Controller          controller,
            LV2UI_Widget*             widget,
            const LV2_Feature* const* features)
{
        int argc = 0;
        char *argv[] = {};
    wxEntryStart( argc, argv );
    wxTheApp->CallOnInit();
    wxTheApp->OnRun();

    App* app = (App*)wxTheApp;
    return app;
//   SamplerUI* ui = (SamplerUI*)calloc(1, sizeof(SamplerUI));
//   if (!ui) {
//     return NULL;
//   }

//   ui->write      = write_function;
//   ui->controller = controller;
//   ui->width      = MIN_CANVAS_W;
//   *widget        = NULL;
//   ui->window     = NULL;
//   ui->did_init   = false;

//   // Get host features
//   // clang-format off
//   const char* missing = lv2_features_query(
//     features,
//     LV2_LOG__log,         &ui->logger.log,    false,
//     LV2_URID__map,        &ui->map,           true,
//     LV2_UI__requestValue, &ui->request_value, false,
//     NULL);
//   // clang-format on

//   lv2_log_logger_set_map(&ui->logger, ui->map);
//   if (missing) {
//     lv2_log_error(&ui->logger, "Missing feature <%s>\n", missing);
//     free(ui);
//     return NULL;
//   }

//   // Map URIs and initialise forge
//   map_sampler_uris(ui->map, &ui->uris);
//   lv2_atom_forge_init(&ui->forge, ui->map);
//   peaks_receiver_init(&ui->precv, ui->map);

//   // Construct Gtk UI
//   ui->box         = gtk_vbox_new(FALSE, 4);
//   ui->play_button = gtk_button_new_with_label("▶");
//   ui->canvas      = gtk_drawing_area_new();
//   ui->button_box  = gtk_hbox_new(FALSE, 4);
//   ui->file_button =
//     gtk_file_chooser_button_new("Load Sample", GTK_FILE_CHOOSER_ACTION_OPEN);
//   ui->request_file_button = gtk_button_new_with_label("Request Sample");
//   gtk_widget_set_size_request(ui->canvas, MIN_CANVAS_W, MIN_CANVAS_H);
//   gtk_container_set_border_width(GTK_CONTAINER(ui->box), 4);
//   gtk_box_pack_start(GTK_BOX(ui->box), ui->canvas, TRUE, TRUE, 0);
//   gtk_box_pack_start(GTK_BOX(ui->box), ui->button_box, FALSE, TRUE, 0);
//   gtk_box_pack_start(GTK_BOX(ui->button_box), ui->play_button, FALSE, FALSE, 0);
//   gtk_box_pack_start(
//     GTK_BOX(ui->button_box), ui->request_file_button, FALSE, FALSE, 0);
//   gtk_box_pack_start(GTK_BOX(ui->button_box), ui->file_button, TRUE, TRUE, 0);

//   g_signal_connect(ui->file_button, "file-set", G_CALLBACK(on_file_set), ui);

//   g_signal_connect(
//     ui->request_file_button, "clicked", G_CALLBACK(on_request_file), ui);

//   g_signal_connect(ui->play_button, "clicked", G_CALLBACK(on_play_clicked), ui);

//   g_signal_connect(
//     G_OBJECT(ui->canvas), "expose_event", G_CALLBACK(on_canvas_expose), ui);

//   // Request state (filename) from plugin
//   lv2_atom_forge_set_buffer(&ui->forge, ui->forge_buf, sizeof(ui->forge_buf));
//   LV2_Atom_Forge_Frame frame;
//   LV2_Atom*            msg =
//     (LV2_Atom*)lv2_atom_forge_object(&ui->forge, &frame, 0, ui->uris.patch_Get);

//   assert(msg);

//   lv2_atom_forge_pop(&ui->forge, &frame);

//   ui->write(ui->controller,
//             0,
//             lv2_atom_total_size(msg),
//             ui->uris.atom_eventTransfer,
//             msg);

//   *widget = ui->box;

//   return ui;
}

static void
connect_port(LV2_Handle instance,
             uint32_t   port,
             void*      data)
{
        Amp* amp = (Amp*)instance;

        switch ((PortIndex)port) {
        case AMP_GAIN:
                amp->gain = (const float*)data;
                break;
        case AMP_INPUT:
                amp->input = (const float*)data;
                break;
        case AMP_OUTPUT:
                amp->output = (float*)data;
                break;
        }
}

static void
activate(LV2_Handle instance)
{
}

static void
run(LV2_Handle instance, uint32_t n_samples)
{
        const Amp* amp = (const Amp*)instance;

        // const float        gain   = *(amp->gain);
        // const float* const input  = amp->input;
        // float* const       output = amp->output;

        // const float coef = DB_CO(gain);

        // for (uint32_t pos = 0; pos < n_samples; pos++) {
        //         output[pos] = input[pos] * coef;
        // }
}

static void
deactivate(LV2_Handle instance)
{
}

static const void*
extension_data(const char* uri)
{
        return NULL;
}

static void
cleanup(LV2UI_Handle handle)
{
//   EgScopeUI* ui = (EgScopeUI*)handle;
//   /* Send UIOff message to plugin, which will save state and disable message
//    * transmission. */
//   send_ui_disable(ui);
//   gtk_widget_destroy(ui->darea);
//   free(ui);
}

static void
port_event(LV2UI_Handle handle,
           uint32_t     port_index,
           uint32_t     buffer_size,
           uint32_t     format,
           const void*  buffer)
{
//   EgScopeUI*      ui   = (EgScopeUI*)handle;
//   const LV2_Atom* atom = (const LV2_Atom*)buffer;

//   /* Check type of data received
//    *  - format == 0: Control port event (float)
//    *  - format > 0:  Message (atom)
//    */
//   if (format == ui->uris.atom_eventTransfer &&
//       lv2_atom_forge_is_object_type(&ui->forge, atom->type)) {
//     const LV2_Atom_Object* obj = (const LV2_Atom_Object*)atom;
//     if (obj->body.otype == ui->uris.RawAudio) {
//       recv_raw_audio(ui, obj);
//     } else if (obj->body.otype == ui->uris.ui_State) {
//       recv_ui_state(ui, obj);
//     }
//   }
}

static const LV2UI_Descriptor descriptor = {
	AMP_URI,
	instantiate,
	cleanup,
	port_event,
	extension_data
};

LV2_SYMBOL_EXPORT
const LV2UI_Descriptor* lv2ui_descriptor(uint32_t index) {
        return 0 == index ? &descriptor : NULL;
}

