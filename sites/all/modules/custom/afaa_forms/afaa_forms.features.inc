<?php
/**
 * @file
 * afaa_forms.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function afaa_forms_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_entityform_type().
 */
function afaa_forms_default_entityform_type() {
  $items = array();
  $items['get_involved'] = entity_import('entityform_type', '{
    "type" : "get_involved",
    "label" : "Get Involved",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "filtered_html" },
      "submission_rules" : [],
      "notification_text" : "",
      "notify_emails" : "",
      "validation_rules" : [],
      "submit_button_text" : "Send Message",
      "submission_page_title" : "",
      "submission_text" : {
        "value" : "Thanks you.  Your message has been received.",
        "format" : "filtered_html"
      },
      "submission_show_submitted" : 0,
      "submissions_view" : "entityforms",
      "user_submissions_view" : "",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "1" : "1", "2" : "2", "3" : 0 },
      "resubmit_action" : "new",
      "access_rules" : [],
      "redirect_path" : "",
      "instruction_pre" : { "value" : "", "format" : "filtered_html" }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  $items['site_contact_form'] = entity_import('entityform_type', '{
    "type" : "site_contact_form",
    "label" : "Contact",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "filtered_html" },
      "submit_button_text" : "Send Message",
      "submission_page_title" : "",
      "submission_text" : {
        "value" : "Thanks you.  Your message has been received.",
        "format" : "filtered_html"
      },
      "submission_show_submitted" : 0,
      "submissions_view" : "entityforms",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "1" : "1", "2" : "2", "3" : 0 },
      "resubmit_action" : "new",
      "access_rules" : [],
      "redirect_path" : "",
      "instruction_pre" : { "value" : "", "format" : "filtered_html" },
      "submission_rules" : { "rules_entitiyform_email_site_admin_" : "rules_entitiyform_email_site_admin_" },
      "notification_text" : "",
      "notify_emails" : ""
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  return $items;
}
