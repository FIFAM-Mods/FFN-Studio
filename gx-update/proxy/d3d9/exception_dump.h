#pragma once

// Exportable
int InstallExceptionCatcher(void(*OnException)(const char* log));
