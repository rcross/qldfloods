// $Id: README.txt,v 1.2 2010/11/15 23:46:19 geokat Exp $

Module: RPX (Janrain Engage)

Author: Peat Bakke <peat@janrain.com>,
        George Katsitadze <george@janrain.com>,
        Nathan Rambeck <http://nathan.rambeck.org>,
        Rendahl Weishar <ren@janrain.com>

Description
===========

It's a set of modules for using Janrain's Engage (formerly RPX)
service in Drupal).

Engage (http://www.janrain.com/products/engage/) provides simple
registration and login for OpenID, Facebook, MySpace, AOL, Yahoo!,
Google, Twitter, Windows Live, and other identity providers, as well
as social sharing on Facebook, Twitter, Myspace, Linkedin and
Yahoo!. Tres chic.

Installation
============

1. Download the tarball, unzip the source, and put the resulting
   directory into the modules/ directory of your Drupal application.

2. Enable the modules in Drupal at Administer > Modules > Janrain Engage

3. Provide your Engage API Key at Administer > Configuration > Janrain Engage

4. Recommended: Change your user settings to allow users to create
   accounts without administrator approval at Administer > Configuration >
   Account Settings

If you don't have an API Key, click the "Setup this site for Engage"
link, and one will be installed for you.

In order to enable sign-in with Facebook, Linkedin, Twitter, MySpace,
Paypal, and Windows Live accounts, as well as social publishing to
Facebook, Twitter, Myspace, Linkedin and Yahoo!, you must register
with the respective services.

Links from the control panel are provided, with step-by-step setup
instructions.

Troubleshooting
===============

Problem: Users get an error during registration that says "The
         configured token URL has not been whitelisted"

Solution: Try editing the app settings in your rpxnow.com account to
          use a wildcard for subdomains. So your domains would include
          mysite.com and also *.mysite.com.

For detailed technical documentation, please visit:

* http://rpxnow.com/docs/
* http://api.drupal.org/
