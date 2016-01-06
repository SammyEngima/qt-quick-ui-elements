#ifndef QTQMLTRICKSPLUGIN_H
#define QTQMLTRICKSPLUGIN_H

#include <QQmlEngine>
#include <qqml.h>
#include <QIcon>

#include "QQuickPolygon.h"
#include "QQuickExtraAnchors.h"
#include "QQuickSvgIconHelper.h"
#include "QQmlMimeIconsHelper.h"
#include "QQuickThemeIconProvider.h"
#include "QQuickGridContainer.h"
#include "QQuickStretchRowContainer.h"
#include "QQuickStretchColumnContainer.h"
#include "QQuickWrapLeftRightContainer.h"

static void registerQtQmlTricksUiElements (QQmlEngine * engine = Q_NULLPTR) {
    Q_INIT_RESOURCE (qtqmltricksicons);
    Q_INIT_RESOURCE (qtqmltricksuielements);

    const char * uri = "QtQmlTricks.UiElements"; // @uri QtQmlTricks.UiElements
    const int    maj = 2;
    const int    min = 0;

    // icon theme
    QIcon::setThemeSearchPaths (QStringList () << ":/QtQmlTricks/UiElements/icons");
    QIcon::setThemeName ("FaenzaIconsLite");

    // shapes
    qmlRegisterType<QQuickPolygon>                       (uri, maj, min, "Polygon");

    // icons
    qmlRegisterType<QQuickSvgIconHelper>                 (uri, maj, min, "SvgIconHelper");
    qmlRegisterType<QQmlMimeIconsHelper>                 (uri, maj, min, "MimeIconsHelper");

    // layouts
    qmlRegisterType<QQuickGridContainer>                 (uri, maj, min, "GridContainer");
    qmlRegisterType<QQuickStretchRowContainer>           (uri, maj, min, "StretchRowContainer");
    qmlRegisterType<QQuickStretchColumnContainer>        (uri, maj, min, "StretchColumnContainer");
    qmlRegisterType<QQuickWrapLeftRightContainer>        (uri, maj, min, "WrapLeftRightContainer");
    qmlRegisterType<QQuickWrapLeftRightContainerBreaker> (uri, maj, min, "WrapBreaker");

    qmlRegisterUncreatableType<QQuickExtraAnchors>       (uri, maj, min, "ExtraAnchors", "!!!");

    if (engine != Q_NULLPTR) {
        engine->addImageProvider ("icon-theme", new QQuickThemeIconProvider);
        engine->addImportPath ("qrc:///imports");
    }
}

#endif // QTQMLTRICKSPLUGIN_H

