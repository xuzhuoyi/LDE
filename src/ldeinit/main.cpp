/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * LDE - for Loongson, Qt based, desktop toolset
 * http://www.loongsoner.com, ftp://ftp.loongsoner.com/
 *
 * Copyright: 2014 LDE team
 * Authors:
 *   Zhuoyi Xu <xzy476386434@vip.qq.com>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */

#include <QCoreApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include "init.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCommandLineOption opMode("m");
    opMode.setValueName("mode");
    QCommandLineParser parser;
    parser.addOption(opMode);
    parser.process(a);
    int m = parser.isSet(opMode) ? parser.value(opMode).toInt() : 1;
    Init *app;
    app = new Init(m);
    return a.exec();
}
