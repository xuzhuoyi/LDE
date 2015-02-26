Name:           lde
Version:        2.0.0 
Release:        1%{?dist}
Summary:        Complete LDE Desktop Environment for end users

License:        GPLv2+
URL:            http://xuzhuoyi.github.io
Source0:        %{name}.tar.gz

BuildRequires:  qt5-qtbase-gui, qt5-qtwebkit-devel, gcc-c++
Requires:       qt5-qtbase, qt5-qtbase-gui, qt5-qtwebkit, openbox, razorqt-panel feh

%description
LDE is the powerful, lightweight, and easy-to-use Free Software desktop platform and suite of applications.
This package includes all the modules released with LDE Desktop Environment that are useful for a desktop user. This includes Looplorer, Looget, LDE Control Center, LooFm, Lootepad, and other useful utilities.


%prep
%setup -q -n %{name}


%build
cd src && %{_libdir}/qt5/bin/qmake lde.pro && make


%install
rm -rf $RPM_BUILD_ROOT
install -d %{buildroot}/usr/
install -d %{buildroot}/usr/bin/
install -d %{buildroot}/usr/share/
install -d %{buildroot}/usr/share/applications/
install -d %{buildroot}/usr/share/xsessions/
install -d %{buildroot}/usr/share/wallpapers/
install usr/bin/* %{buildroot}/usr/bin/
install share/*.desktop %{buildroot}/usr/share/applications/
install shell/startlde %{buildroot}/usr/bin/
install xsessions/LDE.desktop %{buildroot}/usr/share/xsessions/
install wallpapers/lde-default.png %{buildroot}/usr/share/wallpapers/


%files
%doc
%{_bindir}/*
%{_datadir}/applications/*
%{_datadir}/xsessions/*
%{_datadir}/wallpapers/*



%changelog
* Thu Feb 26 2015 Zhuoyi Xu (LDE Team) <xzy476386434@vip.qq.com> - 2.0.0
- Change Ldeabout UI (#64)
