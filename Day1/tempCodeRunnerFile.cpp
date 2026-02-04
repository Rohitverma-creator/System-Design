 ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();
    ShoppingCartStorage *db = new ShoppingCartStorage(cart);
    db->saveToDatabase();