#ifndef LITHIUM_GLOBAL
#define LITHIUM_GLOBAL

#define L_THEME_INIT_WIDGET(className) \
    LThemeManager * manager = LThemeManager::instance(); \
    this->setStyleSheet(this->styleSheet() + manager->getQssForWidget(#className)); \
    connect(manager, &LThemeManager::themeChanged, [=](QString) { \
        this->setStyleSheet(manager->getQssForWidget(#className)); \
    });

#endif // LITHIUM_GLOBAL

