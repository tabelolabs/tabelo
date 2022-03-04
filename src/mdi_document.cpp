/*
    SPDX-FileCopyrightText: 2022 naracanto https://naracanto.github.io

    SPDX-License-Identifier: GPL-3.0-or-later
*/

#include "mdi_document.h"

#include <KLocalizedString>


MdiDocument::MdiDocument(QWidget *parent)
    : TabularDocument(parent)
    , m_url{QUrl()}
    , m_filenameSequenceNumber{0}
    , m_pathVisibleInWindowTitle{false}
{
    static int sequenceNumber = 1;

    setWindowTitle(i18n("Untitled (%1)", sequenceNumber++));
}


void MdiDocument::setUrl(const QUrl &url)
{
    if (url != m_url) {
        m_url = url;
        Q_EMIT urlChanged(url);
    }
}


QUrl MdiDocument::url() const
{
    return m_url;
}


void MdiDocument::setFilenameSequenceNumber(const int number)
{
    if (number != m_filenameSequenceNumber) {
        m_filenameSequenceNumber = number;
        Q_EMIT filenameSequenceNumberChanged(number);
    }
}


int MdiDocument::filenameSequenceNumber() const
{
    return m_filenameSequenceNumber;
}


void MdiDocument::setPathVisibleInWindowTitle(const bool visible)
{
    m_pathVisibleInWindowTitle = visible;
}


bool MdiDocument::isPathVisibleInWindowTitle() const
{
    return m_pathVisibleInWindowTitle;
}