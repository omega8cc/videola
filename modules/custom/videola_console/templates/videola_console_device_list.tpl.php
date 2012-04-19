<?php
/**
 * @file
 *
 * $devices: An associative array of devices.
 * $devices_rendered: List of devices rendered as an HTML table.
 */
?>
<div class="device-list" id="videola-console-services-device-list">
  <h2>Authorized Devices</h2>

  <?php if ($devices_rendered): ?>
    <?php print $devices_rendered; ?>
  <?php else: ?>
    <p><?php print ('There are no devices associated with your account. You can add devices by downloading the appropriate application for your device and starting the authorization process from the device itself.'); ?></p>
  <?php endif ?>

  <p clas="new-device"><a href="<?php print url('device/authorize'); ?>"><?php print t('Authorize a new device'); ?></a></p>
</div>
