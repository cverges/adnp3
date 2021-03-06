
//
// Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
// more contributor license agreements. See the NOTICE file distributed
// with this work for additional information regarding copyright ownership.
// Green Energy Corp licenses this file to you under the Apache License,
// Version 2.0 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// This file was forked on 01/01/2013 by Automatak, LLC and modifications
// have been made to this file. Automatak, LLC licenses these modifications to
// you under the terms of the License.
//

#ifndef __CLR_DNP3_MANAGER_ADAPTER_H_
#define __CLR_DNP3_MANAGER_ADAPTER_H_

using namespace System;
using namespace DNP3::Interface;

namespace opendnp3 {
	class DNP3Manager;
}

namespace DNP3
{	
namespace Adapter
{
	/// <summary>
    /// Factory class used to get the root DNP3 object
    /// </summary>
	public ref class DNP3ManagerFactory 
	{
		public:
			/// <summary>
			/// Create a new IDNP3Manager using the specified concurrency
			/// </summary>
			/// <param name="concurrency">how many threads are allocated to the thread pool</param>        
			/// <returns>IDNP3Manager interface</returns>
			static IDNP3Manager^ CreateManager(System::Int32 concurrency);

			/// <summary>
			/// Create a new IDNP3Manager using the default concurrency
			/// </summary>			
			/// <returns>IDNP3Manager interface</returns>			
			static IDNP3Manager^ CreateManager();

		private:
			DNP3ManagerFactory(){}
	};

	
	ref class DNP3ManagerAdapter : public DNP3::Interface::IDNP3Manager
	{
		public:
			DNP3ManagerAdapter(System::Int32 aConcurrency);
			~DNP3ManagerAdapter();
			
			virtual IChannel^ AddTCPClient(System::String^ name, LogLevel level, System::UInt64 retryMs, System::String^ address, System::UInt16 port);					
			virtual IChannel^ AddTCPServer(System::String^ name, LogLevel level, System::UInt64 retryMs, System::String^ endpoint, System::UInt16 port);
			virtual IChannel^ AddSerial(System::String^ name, LogLevel level, System::UInt64 retryMs, SerialSettings^ settings);

			virtual void AddLogHandler(ILogHandler^ logHandler);			
			
		private:
			opendnp3::DNP3Manager* pMgr;
	};

}}

#endif
