Documentation for drush videola-* commands.

Command: videola-purge-orders

Running this command will nuke all ubercart orders from the site, and also attempts to perform the cleanup that any modules would do when an order is deleted. Because of the way that uc_recurring works it was necessary to add some additional santizing of tables before running uc_order_delete() on an order to ensure that the uc_recurring module doesn't try and do things like go off to Authorize.net and delete a customers CIM profile, or payment profiles from PayPal.

Given the --purge-users flag the command is also capable of removing all user accounts for users that were created as part of a new ubercart transaction as well. Once again the command does some manual processing to delete users since calling user_delete() directly can in some situations under specific configurations cause an e-mail to be sent to the user whose account is being deleted.

Command: videola-generate-orders (1,2,3 ... N)

Generate N number of random ubercart orders. This simulates adding a product or set of products to a user's shopping cart and then going through the checkout workflow creating orders in ubercart and ensuring that the order passes through all 'states' and that all modules have an opportunity to fire their related hooks.

Use --nids=117,118 to specify that a certain set of products should be used when placing an order. If no products are specified the command will pull from the site-wide product list and randomly at 1 to 5 products to each order.

Command: videola-randomize-next-charge

Randomize the next charge date on recurring orders so that at least some of the orders will be charged on the next cron run.

Use the --uid= (1 || <username>) flag to specify a specific user who's next charge date should be set to some random time in the past.