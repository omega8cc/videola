<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function videola_services_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "oauth_common" && $api == "oauth") {
    return array("version" => 1);
  }
  elseif ($module == "services" && $api == "services") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}
