/* $Id$ */
/** @file
 * VBox Qt GUI - UIGlobalSettingsExtension class declaration.
 */

/*
 * Copyright (C) 2010-2017 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */

#ifndef ___UIGlobalSettingsExtension_h___
#define ___UIGlobalSettingsExtension_h___

/* GUI includes: */
#include "UISettingsPage.h"
#include "UIGlobalSettingsExtension.gen.h"

/* Forward declarations: */
struct UIDataSettingsGlobalExtension;
struct UIDataSettingsGlobalExtensionItem;
typedef UISettingsCache<UIDataSettingsGlobalExtension> UISettingsCacheGlobalExtension;


/** Global settings: Extension page. */
class UIGlobalSettingsExtension : public UISettingsPageGlobal, public Ui::UIGlobalSettingsExtension
{
    Q_OBJECT;

public:

    /** Constructs Extension settings page. */
    UIGlobalSettingsExtension();
    /** Destructs Extension settings page. */
    ~UIGlobalSettingsExtension();

    static void doInstallation(QString const &strFilePath, QString const &strDigest, QWidget *pParent, QString *pstrExtPackName);

protected:

    /** Loads data into the cache from corresponding external object(s),
      * this task COULD be performed in other than the GUI thread. */
    virtual void loadToCacheFrom(QVariant &data) /* override */;
    /** Loads data into corresponding widgets from the cache,
      * this task SHOULD be performed in the GUI thread only. */
    virtual void getFromCache() /* override */;

    /** Saves data from corresponding widgets to the cache,
      * this task SHOULD be performed in the GUI thread only. */
    virtual void putToCache() /* override */;
    /** Saves data from the cache to corresponding external object(s),
      * this task COULD be performed in other than the GUI thread. */
    virtual void saveFromCacheTo(QVariant &data) /* overrride */;

    /** Defines TAB order. */
    virtual void setOrderAfter(QWidget *pWidget) /* override */;

    /** Handles translation event. */
    virtual void retranslateUi() /* override */;

private slots:

    /* Handlers: Tree-widget stuff: */
    void sltHandleCurrentItemChange(QTreeWidgetItem *pCurrentItem);
    void sltShowContextMenu(const QPoint &position);

    /* Handlers: Package stuff: */
    void sltInstallPackage();
    void sltRemovePackage();

private:

    /* Prepare UIDataSettingsGlobalExtensionItem basing on CExtPack: */
    void fetchData(const CExtPack &package, UIDataSettingsGlobalExtensionItem &item) const;

    /* Variables: Actions: */
    QAction *m_pActionAdd;
    QAction *m_pActionRemove;

    /** Holds the page data cache instance. */
    UISettingsCacheGlobalExtension *m_pCache;
};

#endif /* !___UIGlobalSettingsExtension_h___ */

