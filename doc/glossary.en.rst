.. Licensed to the Apache Software Foundation (ASF) under one
   or more contributor license agreements.  See the NOTICE file
   distributed with this work for additional information
   regarding copyright ownership.  The ASF licenses this file
   to you under the Apache License, Version 2.0 (the
   "License"); you may not use this file except in compliance
   with the License.  You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing,
   software distributed under the License is distributed on an
   "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
   KIND, either express or implied.  See the License for the
   specific language governing permissions and limitations
   under the License.

=============
Glossary
=============

.. glossary::
   :sorted:

   continuation
      A callable object that contains state. These are are mechanism used by Traffic Server to implement callbacks and
      continued computations. Continued computations are critical to efficient processing of traffic because by avoiding
      any blocking operations that wait on external events. In any such case a continuation is used so that other
      processing can continue until the external event occurs. At that point the continuation is invoked to continue the
      suspended processing. This can be considered similar to co-routines.

   session
      A single connection from a client to Traffic Server, covering all requests and responses on that connection. A
      session starts when the client connection opens, and ends when the connection closes.

   transaction
      A client request and response, either from the origin server or from the cache. A transaction begins when Traffic
      Server receives a request, and ends when Traffic Server sends the response.

   cache volume
      A user defined unit of persistent storage for the cache. Cache volumes are defined in :file:`volume.config`. A
      cache volume is by default spread across :term:`cache span`\ s to increase robustness. Each section of a cache
      volume on a specific cache span is a :term:`cache stripe`.

   cache stripe
      A homogenous persistent store for the cache in a single :term:`cache span`. A stripe always resides
      entirely on a single physical device and is treated as an undifferentiated span of bytes.

   cache span
      The physical storage described by a single line in :file:`storage.config`.

   storage unit
      Obsolete term for :term:`cache span`.

   revalidation
      Verifying that a currently cached object is still valid. This is usually done using an `If-Modified-Since
      <http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.25>`_ request which allows the origin server to
      validate the content without resending the content.

   write cursor
      The location in a :term:`cache stripe` where new data is written.
