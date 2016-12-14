					;-*- mode: lisp; -*-
(cffi:defcfun (wvsprintf "wvsprintfW" :convention :stdcall :library "user32.dll")
    :int
    (lp-output (:string :encoding :utf-16le))
    (lpcwstr (:string :encoding :utf-16le))
    (arglist (:pointer (:struct va-list))))

(cffi:defcfun (wsprintf "wsprintfW" :convention :stdcall :library "user32.dll")
    :int
    (lp-output (:string :encoding :utf-16le))
    (lpcwstr (:string :encoding :utf-16le))
    (arglist (:pointer (:struct va-list))))

(cffi:defcstruct cbt-createwndw
   (lpcs (:pointer (:struct createstructw)))
   (hwnd-insert-after :handle))

(cffi:defcstruct cbtactivatestruct
  (f-mouse :int)
  (h-wnd-active :handle))

(cffi:defcstruct wtssession-notification
  (cb-size :ulong)
  (dw-session-id :ulong))

(cffi:defcstruct eventmsg
  (message :uint)
  (param-l :uint)
  (param-h :uint)
  (time :ulong)
  (hwnd :handle))

(cffi:defcstruct cwpstruct
  (l-param :long)
  (w-param :uint64)
  (message :uint)
  (hwnd :handle))

(cffi:defcstruct cwpretstruct
  (l-result :int64)
  (l-param :long)
  (w-param :uint64)
  (message :uint)
  (hwnd :handle))

(cffi:defcstruct kbdllhookstruct
  (vk-code :ulong)
  (scan-code :ulong)
  (flags :ulong)
  (time :ulong)
  (dw-extra-info :uint64))

(cffi:defcstruct msllhookstruct
  (pt (:pointer (:struct point)))
  (mouse-data :ulong)
  (flags :ulong)
  (time :ulong)
  (dw-extra-info :uint64))

(cffi:defcstruct debughookinfo
  (id-thread :ulong)
  (id-thread-installer :ulong)
  (l-param :long)
  (w-param :uint64)
  (code :int))

(cffi:defcstruct mousehookstruct
  (pt (:pointer (:struct point)))
  (hwnd :handle)
  (w-hit-test-code :uint)
  (dw-extra-info :uint64))

(cffi:defcstruct mousehookstructex
  (mouse-data :ulong))

(cffi:defcstruct hardwarehookstruct
  (hwnd :handle)
  (message :uint)
  (w-param :uint64)
  (l-param :long))

(cffi:defcfun (load-keyboard-layout "LoadKeyboardLayoutW" :convention :stdcall :library "user32.dll")
    :handle
    (pwsz-klid (:string :encoding :utf-16le))
    (flags :uint))

(cffi:defcfun (activate-keyboard-layout "ActivateKeyboardLayout" :convention :stdcall :library "user32.dll")
    :handle
    (hkl :handle)
    (flags :uint))

(cffi:defcfun (activate-keyboard-layout "ActivateKeyboardLayout" :convention :stdcall :library "user32.dll")
    :int
    (hkl :handle)
    (flags :uint))

(cffi:defcfun (to-unicode-ex "ToUnicodeEx" :convention :stdcall :library "user32.dll")
    :int
    (w-virt-key :uint)
    (w-scan-code :uint)
    (lp-key-state :uchar)
    (pwsz-buff (:string :encoding :utf-16le))
    (cch-buff :int)
    (w-flags :uint)
    (dwhkl :handle))

(cffi:defcfun (unload-keyboard-layout "UnloadKeyboardLayout" :convention :stdcall :library "user32.dll")
    :int
    (hkl :handle))

(cffi:defcfun (get-keyboard-layout-name "GetKeyboardLayoutNameW" :convention :stdcall :library "user32.dll")
    :int
    (pwsz-klid (:string :encoding :utf-16le)))

(cffi:defcfun (get-keyboard-layout-list "GetKeyboardLayoutList" :convention :stdcall :library "user32.dll")
    :int
    (n-buff :int))

(cffi:defcfun (get-keyboard-layout "GetKeyboardLayout" :convention :stdcall :library "user32.dll")
    :handle
    (id-thread :ulong))

(cffi:defcstruct mouse-move-point
  (x :int)
  (y :int)
  (time :ulong)
  (dw-extra-info :uint64))

(cffi:defcfun (get-mouse-move-points-ex "GetMouseMovePointsEx" :convention :stdcall :library "user32.dll")
    :int
    (cb-size :uint)
    (lppt (:pointer (:struct mouse-move-point)))
    (lppt-buf (:pointer (:struct mouse-move-point)))
    (n-buf-points :int)
    (resolution :ulong))

(cffi:defcfun (create-desktop "CreateDesktopW" :convention :stdcall :library "user32.dll")
    :handle
    (lpsz-desktop (:string :encoding :utf-16le))
    (lpsz-device (:string :encoding :utf-16le))
    (p-devmode :void)
    (dw-flags :ulong)
    (dw-desired-access :ulong)
    (lpsa (:pointer (:struct lpsecurity-attributes))))

(cffi:defcfun (create-desktop-ex "CreateDesktopExW" :convention :stdcall :library "user32.dll")
    :handle
    (lpsz-desktop (:string :encoding :utf-16le))
    (lpsz-device (:string :encoding :utf-16le))
    (p-devmode :void)
    (dw-flags :ulong)
    (dw-desired-access :ulong)
    (lpsa (:pointer (:struct lpsecurity-attributes)))
    (ul-heap-size :ulong)
    (pvoid (:string :void)))

(cffi:defcfun (open-desktop "OpenDesktopW" :convention :stdcall :library "user32.dll")
    :handle
    (lpsz-desktop (:string :encoding :utf-16le))
    (dw-flags :ulong)
    (f-inherit :int)
    (dw-desired-access :ulong))

(cffi:defcfun (open-input-desktop "OpenInputDesktop" :convention :stdcall :library "user32.dll")
    :handle
    (dw-flags :ulong)
    (f-inherit :int)
    (dw-desired-access :ulong))

(cffi:defcfun (enum-desktops "EnumDesktopsW" :convention :stdcall :library "user32.dll")
    :int
    (hwinsta (:pointer (:struct hwinsta)))
    (lp-enum-func (:pointer (:struct desktopenumprocw)))
    (l-param :long))

(cffi:defcfun (enum-desktop-windows "EnumDesktopWindows" :convention :stdcall :library "user32.dll")
    :int
    (h-desktop :handle)
    (lpfn (:pointer (:struct wndenumproc)))
    (l-param :long))

(cffi:defcfun (switch-desktop "SwitchDesktop" :convention :stdcall :library "user32.dll")
    :int
    (h-desktop :handle))

(cffi:defcfun (set-thread-desktop "SetThreadDesktop" :convention :stdcall :library "user32.dll")
    :int
    (h-desktop :handle))

(cffi:defcfun (close-desktop "CloseDesktop" :convention :stdcall :library "user32.dll")
    :int
    (h-desktop :handle))

(cffi:defcfun (get-thread-desktop "GetThreadDesktop" :convention :stdcall :library "user32.dll")
    :handle
    (dw-thread-id :ulong))

(cffi:defcfun (create-window-station "CreateWindowStationW" :convention :stdcall :library "user32.dll")
    :HWINSTA
    (lpwinsta (:string :encoding :utf-16le))
    (dw-flags :ulong)
    (dw-desired-access :ulong)
    (lpsa (:pointer (:struct lpsecurity-attributes))))

(cffi:defcfun (open-window-station "OpenWindowStationW" :convention :stdcall :library "user32.dll")
    :HWINSTA
    (lpsz-win-sta (:string :encoding :utf-16le))
    (f-inherit :int)
    (dw-desired-access :ulong))

(cffi:defcfun (enum-window-stations "EnumWindowStationsW" :convention :stdcall :library "user32.dll")
    :int
    (lp-enum-func (:pointer (:struct winstaenumprocw)))
    (l-param :long))

(cffi:defcfun (close-window-station "CloseWindowStation" :convention :stdcall :library "user32.dll")
    :int
    (h-win-sta (:pointer (:struct hwinsta))))

(cffi:defcfun (set-process-window-station "SetProcessWindowStation" :convention :stdcall :library "user32.dll")
    :int
    (h-win-sta (:pointer (:struct hwinsta))))

(cffi:defcfun (get-process-window-station "GetProcessWindowStation" :convention :stdcall :library "user32.dll")
    :HWINSTA
    (void :void))

(cffi:defcfun (set-user-object-security "SetUserObjectSecurity" :convention :stdcall :library "user32.dll")
    :int
    (h-obj :int64)
    (p-si-requested (:pointer (:struct psecurity-information)))
    (p-sid (:pointer (:struct psecurity-descriptor))))

(cffi:defcfun (get-user-object-security "GetUserObjectSecurity" :convention :stdcall :library "user32.dll")
    :int
    (h-obj :int64)
    (p-si-requested (:pointer (:struct psecurity-information)))
    (p-sid (:pointer (:struct psecurity-descriptor)))
    (n-length :ulong)
    (lpn-length-needed (:pointer :int32)))

(cffi:defcstruct userobjectflags
  (f-inherit :int)
  (f-reserved :int)
  (dw-flags :ulong))

(cffi:defcfun (get-user-object-information "GetUserObjectInformationW" :convention :stdcall :library "user32.dll")
    :int
    (h-obj :int64)
    (n-index :int)
    (pv-info (:string :void))
    (n-length :ulong)
    (lpn-length-needed (:pointer :int32)))

(cffi:defcfun (set-user-object-information "SetUserObjectInformationW" :convention :stdcall :library "user32.dll")
    :int
    (h-obj :int64)
    (n-index :int)
    (pv-info (:string :void))
    (n-length :ulong))

(cffi:defcstruct wndclassexw
  (cb-size :uint)
  (style :uint)
  (lpfn-wnd-proc (:pointer (:struct wndproc)))
  (cb-cls-extra :int)
  (cb-wnd-extra :int)
  (h-instance :handle)
  (h-icon :handle)
  (h-cursor :handle)
  (hbr-background :handle)
  (lpsz-menu-name (:string :encoding :utf-16le))
  (lpsz-class-name (:string :encoding :utf-16le))
  (h-icon-sm :handle))

(cffi:defcstruct wndclassw
  (style :uint)
  (lpfn-wnd-proc (:pointer (:struct wndproc)))
  (cb-cls-extra :int)
  (cb-wnd-extra :int)
  (h-instance :handle)
  (h-icon :handle)
  (h-cursor :handle)
  (hbr-background :handle)
  (lpsz-menu-name (:string :encoding :utf-16le))
  (lpsz-class-name (:string :encoding :utf-16le)))

(cffi:defcfun (is-hung-app-windo "IsHungAppWindow" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle))

(cffi:defcfun (disable-process-windows-ghosting "DisableProcessWindowsGhosting" :convention :stdcall :library "user32.dll")
    :void
    (void :void))

(cffi:defcstruct msg
  (hwnd :handle)
  (message :uint)
  (w-param :uint64)
  (l-param :long)
  (time :ulong)
  (pt (:pointer (:struct point))))

(cffi:defcstruct minmaxinfo
  (pt-reserved (:pointer (:struct point)))
  (pt-max-size (:pointer (:struct point)))
  (pt-max-position (:pointer (:struct point)))
  (pt-min-track-size (:pointer (:struct point)))
  (pt-max-track-size (:pointer (:struct point))))

(cffi:defcstruct copydatastruct
  (dw-data :uint64)
  (cb-data :ulong)
  (lp-data (:string :void)))

(cffi:defcstruct mdinextmenu
  (hmenu-in :handle)
  (hmenu-next :handle)
  (hwnd-next :handle))

(cffi:defcfun (register-window-message "RegisterWindowMessageW" :convention :stdcall :library "user32.dll")
    :uint
    (lp-string (:string :encoding :utf-16le)))

(cffi:defcstruct windowpos
  (hwnd :handle)
  (hwnd-insert-after :handle)
  (x :int)
  (y :int)
  (cx :int)
  (cy :int)
  (flags :uint))

(cffi:defcstruct nccalcsize-params
  (rgrc (:pointer (:struct rect)))
  (lppos (:pointer (:struct pwindowpos))))

(cffi:defcstruct trackmouseevent
  (cb-size :ulong)
  (dw-flags :ulong)
  (hwnd-track :handle)
  (dw-hover-time :ulong))

(cffi:defcfun (track-mouse-event "TrackMouseEvent" :convention :stdcall :library "user32.dll")
    :int
    (lp-event-track (:pointer (:struct trackmouseevent))))

(cffi:defcfun (draw-edge "DrawEdge" :convention :stdcall :library "user32.dll")
    :int
    (hdc :handle)
    (qrc (:pointer (:struct rect)))
    (edge :uint)
    (grf-flags :uint))

(cffi:defcfun (draw-frame-control "DrawFrameControl" :convention :stdcall :library "user32.dll")
    :int
    (hdc :handle)
    (lprect (:pointer (:struct rect)))
    (uint :uint)
    (uint :uint))

(cffi:defcfun (draw-caption "DrawCaption" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (hdc :handle)
    (lprect (:pointer (:struct rect)))
    (flags :uint))

(cffi:defcfun (draw-animated-rects "DrawAnimatedRects" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (id-ani :int)
    (lprc-from (:pointer (:struct rect)))
    (lprc-to (:pointer (:struct rect))))

(cffi:defcstruct accel
  (f-virt :ushort)
  (key :ushort)
  (cmd :ulong))

(cffi:defcstruct paintstruct
  (hdc :handle)
  (f-erase :int)
  (rc-paint (:pointer (:struct rect)))
  (f-restore :int)
  (f-inc-update :int)
  (rgb-reserved[32] :uchar))

(cffi:defcstruct createstructw
  (lp-create-params (:pointer :void))
  (h-instance :handle)
  (h-menu :handle)
  (hwnd-parent :handle)
  (cy :int)
  (cx :int)
  (y :int)
  (x :int)
  (style :long)
  (lpsz-name (:string :encoding :utf-16le))
  (lpsz-class (:string :encoding :utf-16le))
  (dw-ex-style :ulong))

(cffi:defcstruct windowplacement
  (length :uint)
  (flags :uint)
  (show-cmd :uint)
  (pt-min-position (:pointer (:struct point)))
  (pt-max-position (:pointer (:struct point)))
  (rc-normal-position (:pointer (:struct rect))))

(cffi:defcstruct nmhdr
  (hwnd-from :handle)
  (id-from :uint64)
  (code :uint))

(cffi:defcstruct stylestruct
  (style-old :ulong)
  (style-new :ulong))

(cffi:defcstruct measureitemstruct
  (ctl-type :uint)
  (ctl-id :uint)
  (item-id :uint)
  (item-width :uint)
  (item-height :uint)
  (item-data :uint64))

(cffi:defcstruct drawitemstruct
  (ctl-type :uint)
  (ctl-id :uint)
  (item-id :uint)
  (item-action :uint)
  (item-state :uint)
  (hwnd-item :handle)
  (h-dc :handle)
  (rc-item (:pointer (:struct rect)))
  (item-data :uint64))

(cffi:defcstruct deleteitemstruct
  (ctl-type :uint)
  (ctl-id :uint)
  (item-id :uint)
  (hwnd-item :handle)
  (item-data :uint64))

(cffi:defcstruct compareitemstruct
  (ctl-type :uint)
  (ctl-id :uint)
  (hwnd-item :handle)
  (item-i-d1 :uint)
  (item-data1 :uint64)
  (item-i-d2 :uint)
  (item-data2 :uint64)
  (dw-locale-id :ulong))

(cffi:defcfun (get-message "GetMessageW" :convention :stdcall :library "user32.dll")
    :int
    (lp-msg (:pointer (:struct lpmsg)))
    (h-wnd :handle)
    (w-msg-filter-min :uint)
    (w-msg-filter-max :uint))

(cffi:defcfun (translate-message "TranslateMessage" :convention :stdcall :library "user32.dll")
    :int
    (lp-msg (:pointer (:struct msg))))

(cffi:defcfun (dispatch-message "DispatchMessageW" :convention :stdcall :library "user32.dll")
    :int64
    (lp-msg (:pointer (:struct msg))))

(cffi:defcfun (set-message-queue "SetMessageQueue" :convention :stdcall :library "user32.dll")
    :int
    (c-messages-max :int))

(cffi:defcfun (peek-message "PeekMessageW" :convention :stdcall :library "user32.dll")
    :int
    (lp-msg (:pointer (:struct lpmsg)))
    (h-wnd :handle)
    (w-msg-filter-min :uint)
    (w-msg-filter-max :uint)
    (w-remove-msg :uint))

(cffi:defcfun (register-hot-key "RegisterHotKey" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (id :int)
    (fs-modifiers :uint)
    (vk :uint))

(cffi:defcfun (unregister-hot-key "UnregisterHotKey" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (id :int))

(cffi:defcfun (exit-windows-ex "ExitWindowsEx" :convention :stdcall :library "user32.dll")
    :int
    (u-flags :uint)
    (dw-reason :ulong))

(cffi:defcfun (swap-mouse-button "SwapMouseButton" :convention :stdcall :library "user32.dll")
    :int
    (f-swap :int))

(cffi:defcfun (get-message-pos "GetMessagePos" :convention :stdcall :library "user32.dll")
    :ulong
    (void :void))

(cffi:defcfun (get-message-time "GetMessageTime" :convention :stdcall :library "user32.dll")
    :long
    (void :void))

(cffi:defcfun (get-message-extra-info "GetMessageExtraInfo" :convention :stdcall :library "user32.dll")
    :long
    (void :void))

(cffi:defcfun (is-wow64-message "IsWow64Message" :convention :stdcall :library "user32.dll")
    :int
    (void :void))

(cffi:defcfun (set-message-extra-info "SetMessageExtraInfo" :convention :stdcall :library "user32.dll")
    :long
    (l-param :long))

(cffi:defcfun (send-message "SendMessageW" :convention :stdcall :library "user32.dll")
    :int64
    (h-wnd :handle)
    (msg :uint)
    (w-param :uint64)
    (l-param :long))

(cffi:defcfun (send-message-timeout "SendMessageTimeoutW" :convention :stdcall :library "user32.dll")
    :int64
    (h-wnd :handle)
    (msg :uint)
    (w-param :uint64)
    (l-param :long)
    (fu-flags :uint)
    (u-timeout :uint)
    (lpdw-result (:pointer :uint64)))

(cffi:defcfun (send-notify-message "SendNotifyMessageW" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (msg :uint)
    (w-param :uint64)
    (l-param :long))

(cffi:defcfun (send-message-callback "SendMessageCallbackW" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (msg :uint)
    (w-param :uint64)
    (l-param :long)
    (lp-result-call-back (:pointer (:struct sendasyncproc)))
    (dw-data :uint64))

(cffi:defcfun (broadcast-system-message-ex "BroadcastSystemMessageExW" :convention :stdcall :library "user32.dll")
    :long
    (flags :ulong)
    (lp-info (:pointer :int32))
    (msg :uint)
    (w-param :uint64)
    (l-param :long)
    (pbsm-info (:pointer (:struct pbsminfo))))

(cffi:defcfun (broadcast-system-message "BroadcastSystemMessageW" :convention :stdcall :library "user32.dll")
    :long
    (flags :ulong)
    (lp-info (:pointer :int32))
    (msg :uint)
    (w-param :uint64)
    (l-param :long))

(cffi:defcfun (broadcast-system-message "BroadcastSystemMessage" :convention :stdcall :library "user32.dll")
    :long
    (flags :ulong)
    (lp-info (:pointer :int32))
    (msg :uint)
    (w-param :uint64)
    (l-param :long))

(cffi:defcfun (register-device-notification "RegisterDeviceNotificationW" :convention :stdcall :library "user32.dll")
    :HDEVNOTIFY
    (h-recipient :int64)
    (notification-filter (:pointer :void))
    (flags :ulong))

(cffi:defcfun (unregister-device-notification "UnregisterDeviceNotification" :convention :stdcall :library "user32.dll")
    :int
    (handle (:pointer (:struct hdevnotify))))

(cffi:defcfun (register-power-setting-notification "RegisterPowerSettingNotification" :convention :stdcall :library "user32.dll")
    :HPOWERNOTIFY
    (h-recipient :int64)
    (power-setting-guid (:pointer (:struct lpcguid)))
    (flags :ulong))

(cffi:defcfun (unregister-power-setting-notification "UnregisterPowerSettingNotification" :convention :stdcall :library "user32.dll")
    :int
    (handle (:pointer (:struct hpowernotify))))

(cffi:defcfun (post-message "PostMessageW" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (msg :uint)
    (w-param :uint64)
    (l-param :long))

(cffi:defcfun (post-thread-message "PostThreadMessageW" :convention :stdcall :library "user32.dll")
    :int
    (id-thread :ulong)
    (msg :uint)
    (w-param :uint64)
    (l-param :long))

(cffi:defcfun (attach-thread-input "AttachThreadInput" :convention :stdcall :library "user32.dll")
    :int
    (id-attach :ulong)
    (id-attach-to :ulong)
    (f-attach :int))

(cffi:defcfun (reply-message "ReplyMessage" :convention :stdcall :library "user32.dll")
    :int
    (l-result :int64))

(cffi:defcfun (wait-message "WaitMessage" :convention :stdcall :library "user32.dll")
    :int
    (void :void))

(cffi:defcfun (wait-for-input-idle "WaitForInputIdle" :convention :stdcall :library "user32.dll")
    :ulong
    (h-process :int64)
    (dw-milliseconds :ulong))

(cffi:defcfun (def-window-proc "DefWindowProcW" :convention :stdcall :library "user32.dll")
    :int64
    (h-wnd :handle)
    (msg :uint)
    (w-param :uint64)
    (l-param :long))

(cffi:defcfun (post-quit-message "PostQuitMessage" :convention :stdcall :library "user32.dll")
    :void
    (n-exit-code :int))

(cffi:defcfun (call-window-proc "CallWindowProcW" :convention :stdcall :library "user32.dll")
    :int64
    (lp-prev-wnd-func (:pointer (:struct wndproc)))
    (h-wnd :handle)
    (msg :uint)
    (w-param :uint64)
    (l-param :long))

(cffi:defcfun (call-window-proc "CallWindowProcW" :convention :stdcall :library "user32.dll")
    :int64
    (lp-prev-wnd-func (:pointer (:struct farproc)))
    (h-wnd :handle)
    (msg :uint)
    (w-param :uint64)
    (l-param :long))

(cffi:defcfun (in-send-message "InSendMessage" :convention :stdcall :library "user32.dll")
    :int
    (void :void))

(cffi:defcfun (in-send-message-ex "InSendMessageEx" :convention :stdcall :library "user32.dll")
    :ulong
    (lp-reserved (:pointer :void)))

(cffi:defcfun (get-double-click-time "GetDoubleClickTime" :convention :stdcall :library "user32.dll")
    :uint
    (void :void))

(cffi:defcfun (set-double-click-time "SetDoubleClickTime" :convention :stdcall :library "user32.dll")
    :int
    (uint :uint))

(cffi:defcfun (register-class "RegisterClassW" :convention :stdcall :library "user32.dll")
    :int16
    (lp-wnd-class (:pointer (:struct wndclassw))))

(cffi:defcfun (unregister-class "UnregisterClassW" :convention :stdcall :library "user32.dll")
    :int
    (lp-class-name (:string :encoding :utf-16le))
    (h-instance :handle))

(cffi:defcfun (get-class-info "GetClassInfoW" :convention :stdcall :library "user32.dll")
    :int
    (h-instance :handle)
    (lp-class-name (:string :encoding :utf-16le))
    (lp-wnd-class (:pointer (:struct lpwndclassw))))

(cffi:defcfun (register-class-ex "RegisterClassExW" :convention :stdcall :library "user32.dll")
    :int16
    (wndclassexw (:pointer (:struct const))))

(cffi:defcfun (get-class-info-ex "GetClassInfoExW" :convention :stdcall :library "user32.dll")
    :int
    (h-instance :handle)
    (lpsz-class (:string :encoding :utf-16le))
    (lpwcx (:pointer (:struct lpwndclassexw))))

(cffi:defcfun (create-window-ex "CreateWindowExW" :convention :stdcall :library "user32.dll")
    :handle
    (dw-ex-style :ulong)
    (lp-class-name (:string :encoding :utf-16le))
    (lp-window-name (:string :encoding :utf-16le))
    (dw-style :ulong)
    (x :int)
    (y :int)
    (n-width :int)
    (n-height :int)
    (h-wnd-parent :handle)
    (h-menu :handle)
    (h-instance :handle)
    (lp-param (:pointer :void)))

(cffi:defcfun (is-windo "IsWindow" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

(cffi:defcfun (is-menu "IsMenu" :convention :stdcall :library "user32.dll")
    :int
    (h-menu :handle))

(cffi:defcfun (is-child "IsChild" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd-parent :handle)
    (h-wnd :handle))

(cffi:defcfun (destroy-windo "DestroyWindow" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

(cffi:defcfun (show-windo "ShowWindow" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (n-cmd-show :int))

(cffi:defcfun (animate-windo "AnimateWindow" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (dw-time :ulong)
    (dw-flags :ulong))

(cffi:defcfun (update-layered-windo "UpdateLayeredWindow" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (hdc-dst :handle)
    (ppt-dst (:pointer (:struct point)))
    (psize (:pointer (:struct size)))
    (hdc-src :handle)
    (ppt-src (:pointer (:struct point)))
    (cr-key :int32)
    (pblend (:pointer (:struct blendfunction)))
    (dw-flags :ulong))

(cffi:defcstruct updatelayeredwindowinfo
  (cb-size :ulong)
  (hdc-dst :handle)
  (ppt-dst (:pointer (:struct point)))
  (psize (:pointer (:struct size)))
  (hdc-src :handle)
  (ppt-src (:pointer (:struct point)))
  (cr-key :int32)
  (pblend (:pointer (:struct blendfunction)))
  (dw-flags :ulong)
  (prc-dirty (:pointer (:struct rect))))

(cffi:defcfun (update-layered-window-indirect "UpdateLayeredWindowIndirect" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (p-ulw-info (:pointer (:struct updatelayeredwindowinfo))))

(cffi:defcfun (get-layered-window-attributes "GetLayeredWindowAttributes" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (pcr-key :int32)
    (pb-alpha :uchar)
    (pdw-flags :ulong))

(cffi:defcfun (print-windo "PrintWindow" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (hdc-blt :handle)
    (n-flags :uint))

(cffi:defcfun (set-layered-window-attributes "SetLayeredWindowAttributes" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (cr-key :int32)
    (b-alpha :uchar)
    (dw-flags :ulong))

(cffi:defcfun (show-window-async "ShowWindowAsync" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (n-cmd-show :int))

(cffi:defcfun (flash-windo "FlashWindow" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (b-invert :int))

(cffi:defcfun (flash-window-ex "FlashWindowEx" :convention :stdcall :library "user32.dll")
    :int
    (pfwi (:pointer (:struct pflashwinfo))))

(cffi:defcfun (show-owned-popups "ShowOwnedPopups" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (f-show :int))

(cffi:defcfun (open-icon "OpenIcon" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

(cffi:defcfun (close-windo "CloseWindow" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

(cffi:defcfun (move-windo "MoveWindow" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (x :int)
    (y :int)
    (n-width :int)
    (n-height :int)
    (b-repaint :int))

(cffi:defcfun (set-window-pos "SetWindowPos" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (h-wnd-insert-after :handle)
    (x :int)
    (y :int)
    (cx :int)
    (cy :int)
    (u-flags :uint))

(cffi:defcfun (get-window-placement "GetWindowPlacement" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lpwndpl (:pointer (:struct windowplacement))))

(cffi:defcfun (set-window-placement "SetWindowPlacement" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lpwndpl (:pointer (:struct windowplacement))))

(cffi:defcfun (get-window-display-affinity "GetWindowDisplayAffinity" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (pdw-affinity :ulong))

(cffi:defcfun (set-window-display-affinity "SetWindowDisplayAffinity" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (dw-affinity :ulong))

(cffi:defcfun (begin-defer-window-pos "BeginDeferWindowPos" :convention :stdcall :library "user32.dll")
    :handle
    (n-num-windows :int))

(cffi:defcfun (defer-window-pos "DeferWindowPos" :convention :stdcall :library "user32.dll")
    :handle
    (h-win-pos-info :handle)
    (h-wnd :handle)
    (h-wnd-insert-after :handle)
    (x :int)
    (y :int)
    (cx :int)
    (cy :int)
    (u-flags :uint))

(cffi:defcfun (end-defer-window-pos "EndDeferWindowPos" :convention :stdcall :library "user32.dll")
    :int
    (h-win-pos-info :handle))

(cffi:defcfun (is-window-visible "IsWindowVisible" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

(cffi:defcfun (is-iconic "IsIconic" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

(cffi:defcfun (any-popup "AnyPopup" :convention :stdcall :library "user32.dll")
    :int
    (void :void))

(cffi:defcfun (bring-window-to-top "BringWindowToTop" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

(cffi:defcfun (is-zoomed "IsZoomed" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

(cffi:defcfun (create-dialog-param "CreateDialogParamW" :convention :stdcall :library "user32.dll")
    :handle
    (h-instance :handle)
    (lp-template-name (:string :encoding :utf-16le))
    (h-wnd-parent :handle)
    (lp-dialog-func (:pointer (:struct dlgproc)))
    (dw-init-param :long))

(cffi:defcfun (create-dialog-indirect-param "CreateDialogIndirectParamW" :convention :stdcall :library "user32.dll")
    :handle
    (h-instance :handle)
    (lp-template (:pointer (:struct lpcdlgtemplatew)))
    (h-wnd-parent :handle)
    (lp-dialog-func (:pointer (:struct dlgproc)))
    (dw-init-param :long))

(cffi:defcfun (dialog-box-param "DialogBoxParamW" :convention :stdcall :library "user32.dll")
    :int64
    (h-instance :handle)
    (lp-template-name (:string :encoding :utf-16le))
    (h-wnd-parent :handle)
    (lp-dialog-func (:pointer (:struct dlgproc)))
    (dw-init-param :long))

(cffi:defcfun (dialog-box-indirect-param "DialogBoxIndirectParamW" :convention :stdcall :library "user32.dll")
    :int64
    (h-instance :handle)
    (h-dialog-template (:pointer (:struct lpcdlgtemplatew)))
    (h-wnd-parent :handle)
    (lp-dialog-func (:pointer (:struct dlgproc)))
    (dw-init-param :long))

(cffi:defcfun (end-dialog "EndDialog" :convention :stdcall :library "user32.dll")
    :int
    (h-dlg :handle)
    (n-result :int64))

(cffi:defcfun (get-dlg-item "GetDlgItem" :convention :stdcall :library "user32.dll")
    :handle
    (h-dlg :handle)
    (n-id-dlg-item :int))

(cffi:defcfun (set-dlg-item-int "SetDlgItemInt" :convention :stdcall :library "user32.dll")
    :int
    (h-dlg :handle)
    (n-id-dlg-item :int)
    (u-value :uint)
    (b-signed :int))

(cffi:defcfun (get-dlg-item-int "GetDlgItemInt" :convention :stdcall :library "user32.dll")
    :uint
    (h-dlg :handle)
    (n-id-dlg-item :int)
    (lp-translated :int)
    (b-signed :int))

(cffi:defcfun (set-dlg-item-text "SetDlgItemTextW" :convention :stdcall :library "user32.dll")
    :int
    (h-dlg :handle)
    (n-id-dlg-item :int)
    (lp-string (:string :encoding :utf-16le)))

(cffi:defcfun (get-dlg-item-text "GetDlgItemTextW" :convention :stdcall :library "user32.dll")
    :uint
    (h-dlg :handle)
    (n-id-dlg-item :int)
    (lp-string (:string :encoding :utf-16le))
    (cch-max :int))

(cffi:defcfun (check-dlg-button "CheckDlgButton" :convention :stdcall :library "user32.dll")
    :int
    (h-dlg :handle)
    (n-id-button :int)
    (u-check :uint))

(cffi:defcfun (check-radio-button "CheckRadioButton" :convention :stdcall :library "user32.dll")
    :int
    (h-dlg :handle)
    (n-id-first-button :int)
    (n-id-last-button :int)
    (n-id-check-button :int))

(cffi:defcfun (is-dlg-button-checked "IsDlgButtonChecked" :convention :stdcall :library "user32.dll")
    :uint
    (h-dlg :handle)
    (n-id-button :int))

(cffi:defcfun (send-dlg-item-message "SendDlgItemMessageW" :convention :stdcall :library "user32.dll")
    :int64
    (h-dlg :handle)
    (n-id-dlg-item :int)
    (msg :uint)
    (w-param :uint64)
    (l-param :long))

(cffi:defcfun (get-next-dlg-group-item "GetNextDlgGroupItem" :convention :stdcall :library "user32.dll")
    :handle
    (h-dlg :handle)
    (h-ctl :handle)
    (b-previous :int))

(cffi:defcfun (get-next-dlg-tab-item "GetNextDlgTabItem" :convention :stdcall :library "user32.dll")
    :handle
    (h-dlg :handle)
    (h-ctl :handle)
    (b-previous :int))

(cffi:defcfun (get-dlg-ctrl-id "GetDlgCtrlID" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

(cffi:defcfun (get-dialog-base-units "GetDialogBaseUnits" :convention :stdcall :library "user32.dll")
    :long
    (void :void))

(cffi:defcfun (def-dlg-proc "DefDlgProcW" :convention :stdcall :library "user32.dll")
    :int64
    (h-dlg :handle)
    (msg :uint)
    (w-param :uint64)
    (l-param :long))

(cffi:defcfun (call-msg-filter "CallMsgFilterW" :convention :stdcall :library "user32.dll")
    :int
    (lp-msg (:pointer (:struct lpmsg)))
    (n-code :int))

(cffi:defcfun (open-clipboard "OpenClipboard" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd-new-owner :handle))

(cffi:defcfun (close-clipboard "CloseClipboard" :convention :stdcall :library "user32.dll")
    :int
    (void :void))

(cffi:defcfun (get-clipboard-sequence-number "GetClipboardSequenceNumber" :convention :stdcall :library "user32.dll")
    :ulong
    (void :void))

(cffi:defcfun (get-clipboard-owner "GetClipboardOwner" :convention :stdcall :library "user32.dll")
    :handle
    (void :void))

(cffi:defcfun (set-clipboard-viewer "SetClipboardViewer" :convention :stdcall :library "user32.dll")
    :handle
    (h-wnd-new-viewer :handle))

(cffi:defcfun (get-clipboard-viewer "GetClipboardViewer" :convention :stdcall :library "user32.dll")
    :handle
    (void :void))

(cffi:defcfun (change-clipboard-chain "ChangeClipboardChain" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd-remove :handle)
    (h-wnd-new-next :handle))

(cffi:defcfun (set-clipboard-data "SetClipboardData" :convention :stdcall :library "user32.dll")
    :int64
    (u-format :uint)
    (h-mem :int64))

(cffi:defcfun (get-clipboard-data "GetClipboardData" :convention :stdcall :library "user32.dll")
    :int64
    (u-format :uint))

(cffi:defcfun (register-clipboard-format "RegisterClipboardFormatW" :convention :stdcall :library "user32.dll")
    :uint
    (lpsz-format (:string :encoding :utf-16le)))

(cffi:defcfun (count-clipboard-formats "CountClipboardFormats" :convention :stdcall :library "user32.dll")
    :int
    (void :void))

(cffi:defcfun (enum-clipboard-formats "EnumClipboardFormats" :convention :stdcall :library "user32.dll")
    :uint
    (format :uint))

(cffi:defcfun (get-clipboard-format-name "GetClipboardFormatNameW" :convention :stdcall :library "user32.dll")
    :int
    (format :uint)
    (lpsz-format-name (:string :encoding :utf-16le))
    (cch-max-count :int))

(cffi:defcfun (empty-clipboard "EmptyClipboard" :convention :stdcall :library "user32.dll")
    :int
    (void :void))

(cffi:defcfun (is-clipboard-format-available "IsClipboardFormatAvailable" :convention :stdcall :library "user32.dll")
    :int
    (format :uint))

(cffi:defcfun (get-priority-clipboard-format "GetPriorityClipboardFormat" :convention :stdcall :library "user32.dll")
    :int
    (pa-format-priority-list :uint)
    (c-formats :int))

(cffi:defcfun (get-open-clipboard-windo "GetOpenClipboardWindow" :convention :stdcall :library "user32.dll")
    :handle
    (void :void))

(cffi:defcfun (add-clipboard-format-listener "AddClipboardFormatListener" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle))

(cffi:defcfun (remove-clipboard-format-listener "RemoveClipboardFormatListener" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle))

(cffi:defcfun (get-updated-clipboard-formats "GetUpdatedClipboardFormats" :convention :stdcall :library "user32.dll")
    :int
    (lpui-formats (:pointer :uint))
    (c-formats :uint)
    (pc-formats-out (:pointer :uint)))

(cffi:defcfun (char-to-oem "CharToOemW" :convention :stdcall :library "user32.dll")
    :int
    (p-src (:string :encoding :utf-16le))
    (p-dst (:pointer :char)))

(cffi:defcfun (oem-to-char "OemToCharW" :convention :stdcall :library "user32.dll")
    :int
    (p-src (:string :encoding :ascii))
    (p-dst (:string :encoding :utf-16le)))

(cffi:defcfun (char-to-oem-buff "CharToOemBuffW" :convention :stdcall :library "user32.dll")
    :int
    (lpsz-src (:string :encoding :utf-16le))
    (lpsz-dst (:pointer :char))
    (cch-dst-length :ulong))

(cffi:defcfun (oem-to-char-buff "OemToCharBuffW" :convention :stdcall :library "user32.dll")
    :int
    (lpsz-src (:string :encoding :ascii))
    (lpsz-dst (:string :encoding :utf-16le))
    (cch-dst-length :ulong))

(cffi:defcfun (char-upper "CharUpperW" :convention :stdcall :library "user32.dll")
    (:string :encoding :utf-16le)
    (lpsz (:string :encoding :utf-16le)))

(cffi:defcfun (char-upper-buff "CharUpperBuffW" :convention :stdcall :library "user32.dll")
    :ulong
    (lpsz (:string :encoding :utf-16le))
    (cch-length :ulong))

(cffi:defcfun (char-lower "CharLowerW" :convention :stdcall :library "user32.dll")
    (:string :encoding :utf-16le)
    (lpsz (:string :encoding :utf-16le)))

(cffi:defcfun (char-lower-buff "CharLowerBuffW" :convention :stdcall :library "user32.dll")
    :ulong
    (lpsz (:string :encoding :utf-16le))
    (cch-length :ulong))

(cffi:defcfun (char-next "CharNextW" :convention :stdcall :library "user32.dll")
    (:string :encoding :utf-16le)
    (lpsz (:string :encoding :utf-16le)))

(cffi:defcfun (char-prev "CharPrevW" :convention :stdcall :library "user32.dll")
    (:string :encoding :utf-16le)
    (lpsz-start (:string :encoding :utf-16le))
    (lpsz-current (:string :encoding :utf-16le)))

(cffi:defcfun (is-char-alpha "IsCharAlphaW" :convention :stdcall :library "user32.dll")
    :int
    (ch :wchar))

(cffi:defcfun (is-char-alpha-numeric "IsCharAlphaNumericW" :convention :stdcall :library "user32.dll")
    :int
    (ch :wchar))

(cffi:defcfun (is-char-upper "IsCharUpperW" :convention :stdcall :library "user32.dll")
    :int
    (ch :wchar))

(cffi:defcfun (is-char-lower "IsCharLowerW" :convention :stdcall :library "user32.dll")
    :int
    (ch :wchar))

(cffi:defcfun (set-focus "SetFocus" :convention :stdcall :library "user32.dll")
    :handle
    (h-wnd :handle))

(cffi:defcfun (get-active-windo "GetActiveWindow" :convention :stdcall :library "user32.dll")
    :handle
    (void :void))

(cffi:defcfun (get-focus "GetFocus" :convention :stdcall :library "user32.dll")
    :handle
    (void :void))

(cffi:defcfun (get-kb-code-page "GetKBCodePage" :convention :stdcall :library "user32.dll")
    :uint
    (void :void))

(cffi:defcfun (get-key-state "GetKeyState" :convention :stdcall :library "user32.dll")
    :short
    (n-virt-key :int))

(cffi:defcfun (get-async-key-state "GetAsyncKeyState" :convention :stdcall :library "user32.dll")
    :short
    (v-key :int))

(cffi:defcfun (get-keyboard-state "GetKeyboardState" :convention :stdcall :library "user32.dll")
    :int
    (lp-key-state (:pointer :int8)))

(cffi:defcfun (set-keyboard-state "SetKeyboardState" :convention :stdcall :library "user32.dll")
    :int
    (lp-key-state (:pointer :uchar)))

(cffi:defcfun (get-key-name-text "GetKeyNameTextW" :convention :stdcall :library "user32.dll")
    :int
    (l-param :long)
    (lp-string (:string :encoding :utf-16le))
    (cch-size :int))

(cffi:defcfun (get-keyboard-type "GetKeyboardType" :convention :stdcall :library "user32.dll")
    :int
    (n-type-flag :int))

(cffi:defcfun (to-ascii "ToAscii" :convention :stdcall :library "user32.dll")
    :int
    (u-virt-key :uint)
    (u-scan-code :uint)
    (lp-key-state :uchar)
    (lp-char (:pointer :int16))
    (u-flags :uint))

(cffi:defcfun (to-ascii-ex "ToAsciiEx" :convention :stdcall :library "user32.dll")
    :int
    (u-virt-key :uint)
    (u-scan-code :uint)
    (lp-key-state :uchar)
    (lp-char (:pointer :int16))
    (u-flags :uint)
    (dwhkl :handle))

(cffi:defcfun (to-unicode "ToUnicode" :convention :stdcall :library "user32.dll")
    :int
    (w-virt-key :uint)
    (w-scan-code :uint)
    (lp-key-state :uchar)
    (pwsz-buff (:string :encoding :utf-16le))
    (cch-buff :int)
    (w-flags :uint))

(cffi:defcfun (oem-key-scan "OemKeyScan" :convention :stdcall :library "user32.dll")
    :ulong
    (w-oem-char :ushort))

(cffi:defcfun (vk-key-scan "VkKeyScanW" :convention :stdcall :library "user32.dll")
    :short
    (ch :wchar))

(cffi:defcfun (vk-key-scan-ex "VkKeyScanExW" :convention :stdcall :library "user32.dll")
    :short
    (ch :wchar)
    (dwhkl :handle))

(cffi:defcfun (keybd-event "keybd-event" :convention :stdcall :library "user32.dll")
    :void
    (b-vk :uchar)
    (b-scan :uchar)
    (dw-flags :ulong)
    (dw-extra-info :uint64))

(cffi:defcfun (mouse-event "mouse-event" :convention :stdcall :library "user32.dll")
    :void
    (dw-flags :ulong)
    (dx :ulong)
    (dy :ulong)
    (dw-data :ulong)
    (dw-extra-info :uint64))

(cffi:defcstruct mouseinput
  (dx :long)
  (dy :long)
  (mouse-data :ulong)
  (dw-flags :ulong)
  (time :ulong)
  (dw-extra-info :uint64))

(cffi:defcstruct keybdinput
  (w-vk :ushort)
  (w-scan :ushort)
  (dw-flags :ulong)
  (time :ulong)
  (dw-extra-info :uint64))

(cffi:defcstruct hardwareinput
  (u-msg :ulong)
  (w-param-l :ushort)
  (w-param-h :ushort))

(cffi:defcstruct input
  (type :ulong)
  (union (:pointer (:struct union)))
  (mi (:pointer (:struct mouseinput)))
  (ki (:pointer (:struct keybdinput)))
  (hi (:pointer (:struct hardwareinput))))

(cffi:defcfun (send-input "SendInput" :convention :stdcall :library "user32.dll")
    :uint
    (c-inputs :uint)
    (p-inputs (:pointer (:struct lpinput)))
    (cb-size :int))

(cffi:defcstruct touchinput
  (x :long)
  (y :long)
  (h-source :int64)
  (dw-id :ulong)
  (dw-flags :ulong)
  (dw-mask :ulong)
  (dw-time :ulong)
  (dw-extra-info :uint64)
  (cx-contact :ulong)
  (cy-contact :ulong))

(cffi:defcfun (get-touch-input-info "GetTouchInputInfo" :convention :stdcall :library "user32.dll")
    :int
    (h-touch-input (:pointer (:struct htouchinput))))

(cffi:defcfun (close-touch-input-handle "CloseTouchInputHandle" :convention :stdcall :library "user32.dll")
    :int
    (h-touch-input (:pointer (:struct htouchinput))))

(cffi:defcfun (register-touch-windo "RegisterTouchWindow" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (ul-flags :ulong))

(cffi:defcfun (unregister-touch-windo "UnregisterTouchWindow" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle))

(cffi:defcfun (is-touch-windo "IsTouchWindow" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (pul-flags (:pointer :ulong)))

(cffi:defcstruct lastinputinfo
  (cb-size :uint)
  (dw-time :ulong))

(cffi:defcfun (get-last-input-info "GetLastInputInfo" :convention :stdcall :library "user32.dll")
    :int
    (plii (:pointer (:struct plastinputinfo))))

(cffi:defcfun (map-virtual-key "MapVirtualKeyW" :convention :stdcall :library "user32.dll")
    :uint
    (u-code :uint)
    (u-map-type :uint))

(cffi:defcfun (map-virtual-key-ex "MapVirtualKeyExW" :convention :stdcall :library "user32.dll")
    :uint
    (u-code :uint)
    (u-map-type :uint)
    (dwhkl :handle))

(cffi:defcfun (get-input-state "GetInputState" :convention :stdcall :library "user32.dll")
    :int
    (void :void))

(cffi:defcfun (get-queue-status "GetQueueStatus" :convention :stdcall :library "user32.dll")
    :ulong
    (flags :uint))

(cffi:defcfun (get-capture "GetCapture" :convention :stdcall :library "user32.dll")
    :handle
    (void :void))

(cffi:defcfun (set-capture "SetCapture" :convention :stdcall :library "user32.dll")
    :handle
    (h-wnd :handle))

(cffi:defcfun (release-capture "ReleaseCapture" :convention :stdcall :library "user32.dll")
    :int
    (void :void))

(cffi:defcfun (msg-wait-for-multiple-objects "MsgWaitForMultipleObjects" :convention :stdcall :library "user32.dll")
    :ulong
    (n-count :ulong)
    (p-handles :int64)
    (f-wait-all :int)
    (dw-milliseconds :ulong)
    (dw-wake-mask :ulong))

(cffi:defcfun (msg-wait-for-multiple-objects-ex "MsgWaitForMultipleObjectsEx" :convention :stdcall :library "user32.dll")
    :ulong
    (n-count :ulong)
    (p-handles :int64)
    (dw-milliseconds :ulong)
    (dw-wake-mask :ulong)
    (dw-flags :ulong))

(cffi:defcfun (set-timer "SetTimer" :convention :stdcall :library "user32.dll")
    :uint64
    (h-wnd :handle)
    (n-id-event :uint64)
    (u-elapse :uint)
    (lp-timer-func (:pointer (:struct timerproc))))

(cffi:defcfun (kill-timer "KillTimer" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (u-id-event :uint64))

(cffi:defcfun (is-window-unicode "IsWindowUnicode" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

(cffi:defcfun (enable-windo "EnableWindow" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (b-enable :int))

(cffi:defcfun (is-window-enabled "IsWindowEnabled" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

(cffi:defcfun (load-accelerators "LoadAcceleratorsW" :convention :stdcall :library "user32.dll")
    :handle
    (h-instance :handle)
    (lp-table-name (:string :encoding :utf-16le)))

(cffi:defcfun (create-accelerator-table "CreateAcceleratorTableW" :convention :stdcall :library "user32.dll")
    :handle
    (paccel (:pointer (:struct lpaccel)))
    (c-accel :int))

(cffi:defcfun (destroy-accelerator-table "DestroyAcceleratorTable" :convention :stdcall :library "user32.dll")
    :int
    (h-accel :handle))

(cffi:defcfun (copy-accelerator-table "CopyAcceleratorTableW" :convention :stdcall :library "user32.dll")
    :int
    (h-accel-src :handle)
    (c-accel-entries :int))

(cffi:defcfun (translate-accelerator "TranslateAcceleratorW" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (h-acc-table :handle)
    (lp-msg (:pointer (:struct lpmsg))))

(cffi:defcfun (get-system-metrics "GetSystemMetrics" :convention :stdcall :library "user32.dll")
    :int
    (n-index :int))

(cffi:defcfun (load-menu "LoadMenuW" :convention :stdcall :library "user32.dll")
    :handle
    (h-instance :handle)
    (lp-menu-name (:string :encoding :utf-16le)))

(cffi:defcfun (load-menu-indirect "LoadMenuIndirectW" :convention :stdcall :library "user32.dll")
    :handle
    (lp-menu-template (:pointer (:struct menutemplatew))))

(cffi:defcfun (get-menu "GetMenu" :convention :stdcall :library "user32.dll")
    :handle
    (h-wnd :handle))

(cffi:defcfun (set-menu "SetMenu" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (h-menu :handle))

(cffi:defcfun (change-menu "ChangeMenuW" :convention :stdcall :library "user32.dll")
    :int
    (h-menu :handle)
    (cmd :uint)
    (lpsz-new-item (:string :encoding :utf-16le))
    (cmd-insert :uint)
    (flags :uint))

(cffi:defcfun (hilite-menu-item "HiliteMenuItem" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (h-menu :handle)
    (u-id-hilite-item :uint)
    (u-hilite :uint))

(cffi:defcfun (get-menu-string "GetMenuStringW" :convention :stdcall :library "user32.dll")
    :int
    (h-menu :handle)
    (u-id-item :uint)
    (lp-string (:string :encoding :utf-16le))
    (cch-max :int)
    (flags :uint))

(cffi:defcfun (get-menu-state "GetMenuState" :convention :stdcall :library "user32.dll")
    :uint
    (h-menu :handle)
    (u-id :uint)
    (u-flags :uint))

(cffi:defcfun (draw-menu-bar "DrawMenuBar" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

(cffi:defcfun (get-system-menu "GetSystemMenu" :convention :stdcall :library "user32.dll")
    :handle
    (h-wnd :handle)
    (b-revert :int))

(cffi:defcfun (create-menu "CreateMenu" :convention :stdcall :library "user32.dll")
    :handle
    (void :void))

(cffi:defcfun (create-popup-menu "CreatePopupMenu" :convention :stdcall :library "user32.dll")
    :handle
    (void :void))

(cffi:defcfun (destroy-menu "DestroyMenu" :convention :stdcall :library "user32.dll")
    :int
    (h-menu :handle))

(cffi:defcfun (check-menu-item "CheckMenuItem" :convention :stdcall :library "user32.dll")
    :ulong
    (h-menu :handle)
    (u-id-check-item :uint)
    (u-check :uint))

(cffi:defcfun (enable-menu-item "EnableMenuItem" :convention :stdcall :library "user32.dll")
    :int
    (h-menu :handle)
    (u-id-enable-item :uint)
    (u-enable :uint))

(cffi:defcfun (get-sub-menu "GetSubMenu" :convention :stdcall :library "user32.dll")
    :handle
    (h-menu :handle)
    (n-pos :int))

(cffi:defcfun (get-menu-item-id "GetMenuItemID" :convention :stdcall :library "user32.dll")
    :uint
    (h-menu :handle)
    (n-pos :int))

(cffi:defcfun (get-menu-item-count "GetMenuItemCount" :convention :stdcall :library "user32.dll")
    :int
    (h-menu :handle))

(cffi:defcfun (insert-menu "InsertMenuW" :convention :stdcall :library "user32.dll")
    :int
    (h-menu :handle)
    (u-position :uint)
    (u-flags :uint)
    (u-id-new-item :uint64)
    (lp-new-item (:string :encoding :utf-16le)))

(cffi:defcfun (append-menu "AppendMenuW" :convention :stdcall :library "user32.dll")
    :int
    (h-menu :handle)
    (u-flags :uint)
    (u-id-new-item :uint64)
    (lp-new-item (:string :encoding :utf-16le)))

(cffi:defcfun (modify-menu "ModifyMenuW" :convention :stdcall :library "user32.dll")
    :int
    (h-mnu :handle)
    (u-position :uint)
    (u-flags :uint)
    (u-id-new-item :uint64)
    (lp-new-item (:string :encoding :utf-16le)))

(cffi:defcfun (hmenu "HMENU" :convention :stdcall :library "user32.dll")
    :int
    (u-position :uint)
    (u-flags :uint))

(cffi:defcfun (delete-menu "DeleteMenu" :convention :stdcall :library "user32.dll")
    :int
    (h-menu :handle)
    (u-position :uint)
    (u-flags :uint))

(cffi:defcfun (set-menu-item-bitmaps "SetMenuItemBitmaps" :convention :stdcall :library "user32.dll")
    :int
    (h-menu :handle)
    (u-position :uint)
    (u-flags :uint)
    (h-bitmap-unchecked :handle)
    (h-bitmap-checked :handle))

(cffi:defcfun (get-menu-check-mark-dimensions "GetMenuCheckMarkDimensions" :convention :stdcall :library "user32.dll")
    :long
    (void :void))

(cffi:defcfun (track-popup-menu "TrackPopupMenu" :convention :stdcall :library "user32.dll")
    :int
    (h-menu :handle)
    (u-flags :uint)
    (x :int)
    (y :int)
    (n-reserved :int)
    (h-wnd :handle)
    (prc-rect (:pointer (:struct rect))))

(cffi:defcstruct tpmparams
  (cb-size :uint)
  (rc-exclude (:pointer (:struct rect))))

(cffi:defcfun (track-popup-menu-ex "TrackPopupMenuEx" :convention :stdcall :library "user32.dll")
    :int
    (hmenu :handle)
    (uint :uint)
    (int :int)
    (int :int)
    (hwnd :handle)
    (lptpmparams (:pointer (:struct lptpmparams))))

(cffi:defcfun (calculate-popup-window-position "CalculatePopupWindowPosition" :convention :stdcall :library "user32.dll")
    :int
    (anchor-point (:pointer (:struct point)))
    (window-size (:pointer (:struct size)))
    (flags (:pointer (:struct /)))
    (exclude-rect (:pointer (:struct rect)))
    (popup-window-position (:pointer (:struct rect))))

(cffi:defcstruct menuinfo
  (cb-size :ulong)
  (f-mask :ulong)
  (dw-style :ulong)
  (cy-max :uint)
  (hbr-back :handle)
  (dw-context-help-id :ulong)
  (dw-menu-data :uint64))

(cffi:defcfun (get-menu-info "GetMenuInfo" :convention :stdcall :library "user32.dll")
    :int
    (hmenu :handle)
    (lpmenuinfo (:pointer (:struct lpmenuinfo))))

(cffi:defcfun (set-menu-info "SetMenuInfo" :convention :stdcall :library "user32.dll")
    :int
    (hmenu :handle)
    (lpcmenuinfo (:pointer (:struct lpcmenuinfo))))

(cffi:defcfun (end-menu "EndMenu" :convention :stdcall :library "user32.dll")
    :int
    (void :void))

(cffi:defcstruct menugetobjectinfo
  (dw-flags :ulong)
  (u-pos :uint)
  (hmenu :handle)
  (riid (:string :void))
  (pv-obj (:string :void)))

(cffi:defcstruct menuiteminfow
  (cb-size :uint)
  (f-mask :uint)
  (f-type :uint)
  (f-state :uint)
  (w-id :uint)
  (h-sub-menu :handle)
  (hbmp-checked :handle)
  (hbmp-unchecked :handle)
  (dw-item-data :uint64)
  (dw-type-data (:string :encoding :utf-16le))
  (cch :uint)
  (hbmp-item :handle))

(cffi:defcfun (insert-menu-item "InsertMenuItemW" :convention :stdcall :library "user32.dll")
    :int
    (hmenu :handle)
    (item :uint)
    (f-by-position :int)
    (lpmi (:pointer (:struct lpcmenuiteminfow))))

(cffi:defcfun (get-menu-item-info "GetMenuItemInfoW" :convention :stdcall :library "user32.dll")
    :int
    (hmenu :handle)
    (item :uint)
    (f-by-position :int)
    (lpmii (:pointer (:struct lpmenuiteminfow))))

(cffi:defcfun (set-menu-item-info "SetMenuItemInfoW" :convention :stdcall :library "user32.dll")
    :int
    (hmenu :handle)
    (item :uint)
    (f-by-positon :int)
    (lpmii (:pointer (:struct lpcmenuiteminfow))))

(cffi:defcfun (get-menu-default-item "GetMenuDefaultItem" :convention :stdcall :library "user32.dll")
    :uint
    (h-menu :handle)
    (f-by-pos :uint)
    (gmdi-flags :uint))

(cffi:defcfun (set-menu-default-item "SetMenuDefaultItem" :convention :stdcall :library "user32.dll")
    :int
    (h-menu :handle)
    (u-item :uint)
    (f-by-pos :uint))

(cffi:defcfun (get-menu-item-rect "GetMenuItemRect" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (h-menu :handle)
    (u-item :uint)
    (lprc-item (:pointer (:struct lprect))))

(cffi:defcfun (menu-item-from-point "MenuItemFromPoint" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (h-menu :handle)
    (pt-screen (:pointer (:struct point))))

(cffi:defcstruct dropstruct
  (hwnd-source :handle)
  (hwnd-sink :handle)
  (w-fmt :ulong)
  (dw-data :uint64)
  (pt-drop (:pointer (:struct point)))
  (dw-control-data :ulong))

(cffi:defcfun (drag-object "DragObject" :convention :stdcall :library "user32.dll")
    :ulong
    (hwnd-parent :handle)
    (hwnd-from :handle)
    (fmt :uint)
    (data :uint64)
    (hcur :handle))

(cffi:defcfun (drag-detect "DragDetect" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (pt (:pointer (:struct point))))

(cffi:defcfun (draw-icon "DrawIcon" :convention :stdcall :library "user32.dll")
    :int
    (h-dc :handle)
    (x :int)
    (y :int)
    (h-icon :handle))

(cffi:defcstruct drawtextparams
  (cb-size :uint)
  (i-tab-length :int)
  (i-left-margin :int)
  (i-right-margin :int)
  (ui-length-drawn :uint))

(cffi:defcfun (draw-text "DrawTextW" :convention :stdcall :library "user32.dll")
    :int
    (hdc :handle)
    (lpch-text (:string :encoding :utf-16le))
    (cch-text :int)
    (lprc (:pointer (:struct lprect)))
    (format :uint))

(cffi:defcfun (draw-text-ex "DrawTextExW" :convention :stdcall :library "user32.dll")
    :int
    (hdc :handle)
    (lpch-text (:string :encoding :utf-16le))
    (cch-text :int)
    (lprc (:pointer (:struct lprect)))
    (format :uint)
    (lpdtp (:pointer (:struct lpdrawtextparams))))

(cffi:defcfun (gray-string "GrayStringW" :convention :stdcall :library "user32.dll")
    :int
    (h-dc :handle)
    (h-brush :handle)
    (lp-output-func (:pointer (:struct graystringproc)))
    (lp-data :long)
    (n-count :int)
    (x :int)
    (y :int)
    (n-width :int)
    (n-height :int))

(cffi:defcfun (draw-state "DrawStateW" :convention :stdcall :library "user32.dll")
    :int
    (hdc :handle)
    (hbr-fore :handle)
    (qfn-call-back (:pointer (:struct drawstateproc)))
    (l-data :long)
    (w-data :uint64)
    (x :int)
    (y :int)
    (cx :int)
    (cy :int)
    (u-flags :uint))

(cffi:defcfun (tabbed-text-out "TabbedTextOutW" :convention :stdcall :library "user32.dll")
    :long
    (hdc :handle)
    (x :int)
    (y :int)
    (lp-string (:string :encoding :utf-16le))
    (ch-count :int)
    (n-tab-positions :int)
    (lpn-tab-stop-positions :int)
    (n-tab-origin :int))

(cffi:defcfun (get-tabbed-text-extent "GetTabbedTextExtentW" :convention :stdcall :library "user32.dll")
    :ulong
    (hdc :handle)
    (lp-string (:string :encoding :utf-16le))
    (ch-count :int)
    (n-tab-positions :int)
    (lpn-tab-stop-positions :int))

(cffi:defcfun (update-windo "UpdateWindow" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

(cffi:defcfun (set-active-windo "SetActiveWindow" :convention :stdcall :library "user32.dll")
    :handle
    (h-wnd :handle))

(cffi:defcfun (get-foreground-windo "GetForegroundWindow" :convention :stdcall :library "user32.dll")
    :handle
    (void :void))

(cffi:defcfun (paint-desktop "PaintDesktop" :convention :stdcall :library "user32.dll")
    :int
    (hdc :handle))

(cffi:defcfun (switch-to-this-windo "SwitchToThisWindow" :convention :stdcall :library "user32.dll")
    :void
    (hwnd :handle)
    (f-unknown :int))

(cffi:defcfun (set-foreground-windo "SetForegroundWindow" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

(cffi:defcfun (allow-set-foreground-windo "AllowSetForegroundWindow" :convention :stdcall :library "user32.dll")
    :int
    (dw-process-id :ulong))

(cffi:defcfun (lock-set-foreground-windo "LockSetForegroundWindow" :convention :stdcall :library "user32.dll")
    :int
    (u-lock-code :uint))

(cffi:defcfun (window-from-dc "WindowFromDC" :convention :stdcall :library "user32.dll")
    :handle
    (h-dc :handle))

(cffi:defcfun (get-dc "GetDC" :convention :stdcall :library "user32.dll")
    :handle
    (h-wnd :handle))

(cffi:defcfun (get-dc-ex "GetDCEx" :convention :stdcall :library "user32.dll")
    :handle
    (h-wnd :handle)
    (hrgn-clip :handle)
    (flags :ulong))

(cffi:defcfun (get-window-dc "GetWindowDC" :convention :stdcall :library "user32.dll")
    :handle
    (h-wnd :handle))

(cffi:defcfun (release-dc "ReleaseDC" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (h-dc :handle))

(cffi:defcfun (begin-paint "BeginPaint" :convention :stdcall :library "user32.dll")
    :handle
    (h-wnd :handle)
    (lp-paint (:pointer (:struct lppaintstruct))))

(cffi:defcfun (end-paint "EndPaint" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lp-paint (:pointer (:struct paintstruct))))

(cffi:defcfun (get-update-rect "GetUpdateRect" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lp-rect (:pointer (:struct lprect)))
    (b-erase :int))

(cffi:defcfun (get-update-rgn "GetUpdateRgn" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (h-rgn :handle)
    (b-erase :int))

(cffi:defcfun (set-window-rgn "SetWindowRgn" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (h-rgn :handle)
    (b-redraw :int))

(cffi:defcfun (get-window-rgn "GetWindowRgn" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (h-rgn :handle))

(cffi:defcfun (get-window-rgn-box "GetWindowRgnBox" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lprc (:pointer (:struct lprect))))

(cffi:defcfun (exclude-update-rgn "ExcludeUpdateRgn" :convention :stdcall :library "user32.dll")
    :int
    (h-dc :handle)
    (h-wnd :handle))

(cffi:defcfun (invalidate-rect "InvalidateRect" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lp-rect (:pointer (:struct rect)))
    (b-erase :int))

(cffi:defcfun (validate-rect "ValidateRect" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lp-rect (:pointer (:struct rect))))

(cffi:defcfun (invalidate-rgn "InvalidateRgn" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (h-rgn :handle)
    (b-erase :int))

(cffi:defcfun (validate-rgn "ValidateRgn" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (h-rgn :handle))

(cffi:defcfun (redraw-windo "RedrawWindow" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lprc-update (:pointer (:struct rect)))
    (hrgn-update :handle)
    (flags :uint))

(cffi:defcfun (lock-window-update "LockWindowUpdate" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd-lock :handle))

(cffi:defcfun (scroll-windo "ScrollWindow" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (x-amount :int)
    (y-amount :int)
    (lp-rect (:pointer (:struct rect)))
    (lp-clip-rect (:pointer (:struct rect))))

(cffi:defcfun (scroll-dc "ScrollDC" :convention :stdcall :library "user32.dll")
    :int
    (h-dc :handle)
    (dx :int)
    (dy :int)
    (lprc-scroll (:pointer (:struct rect)))
    (lprc-clip (:pointer (:struct rect)))
    (hrgn-update :handle)
    (lprc-update (:pointer (:struct lprect))))

(cffi:defcfun (scroll-window-ex "ScrollWindowEx" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (dx :int)
    (dy :int)
    (prc-scroll (:pointer (:struct rect)))
    (prc-clip (:pointer (:struct rect)))
    (hrgn-update :handle)
    (prc-update (:pointer (:struct lprect)))
    (flags :uint))

(cffi:defcfun (set-scroll-pos "SetScrollPos" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (n-bar :int)
    (n-pos :int)
    (b-redraw :int))

(cffi:defcfun (get-scroll-pos "GetScrollPos" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (n-bar :int))

(cffi:defcfun (set-scroll-range "SetScrollRange" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (n-bar :int)
    (n-min-pos :int)
    (n-max-pos :int)
    (b-redraw :int))

(cffi:defcfun (get-scroll-range "GetScrollRange" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (n-bar :int)
    (lp-min-pos (:pointer :int))
    (lp-max-pos (:pointer :int)))

(cffi:defcfun (show-scroll-bar "ShowScrollBar" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (w-bar :int)
    (b-show :int))

(cffi:defcfun (enable-scroll-bar "EnableScrollBar" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (w-s-bflags :uint)
    (w-arrows :uint))

(cffi:defcfun (set-prop "SetPropW" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lp-string (:string :encoding :utf-16le))
    (h-data :int64))

(cffi:defcfun (get-prop "GetPropW" :convention :stdcall :library "user32.dll")
    :int64
    (h-wnd :handle)
    (lp-string (:string :encoding :utf-16le)))

(cffi:defcfun (remove-prop "RemovePropW" :convention :stdcall :library "user32.dll")
    :int64
    (h-wnd :handle)
    (lp-string (:string :encoding :utf-16le)))

(cffi:defcfun (enum-props-ex "EnumPropsExW" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lp-enum-func (:pointer (:struct propenumprocexw)))
    (l-param :long))

(cffi:defcfun (enum-props "EnumPropsW" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lp-enum-func (:pointer (:struct propenumprocw))))

(cffi:defcfun (set-window-text "SetWindowTextW" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lp-string (:string :encoding :utf-16le)))

(cffi:defcfun (get-window-text "GetWindowTextW" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lp-string (:string :encoding :utf-16le))
    (n-max-count :int))

(cffi:defcfun (get-window-text-length "GetWindowTextLengthW" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

(cffi:defcfun (get-client-rect "GetClientRect" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lp-rect (:pointer (:struct lprect))))

(cffi:defcfun (get-window-rect "GetWindowRect" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lp-rect (:pointer (:struct lprect))))

(cffi:defcfun (adjust-window-rect "AdjustWindowRect" :convention :stdcall :library "user32.dll")
    :int
    (lp-rect (:pointer (:struct lprect)))
    (dw-style :ulong)
    (b-menu :int))

(cffi:defcfun (adjust-window-rect-ex "AdjustWindowRectEx" :convention :stdcall :library "user32.dll")
    :int
    (lp-rect (:pointer (:struct lprect)))
    (dw-style :ulong)
    (b-menu :int)
    (dw-ex-style :ulong))

(cffi:defcstruct helpinfo
  (cb-size :uint)
  (i-context-type :int)
  (i-ctrl-id :int)
  (h-item-handle :int64)
  (dw-context-id :uint64)
  (mouse-pos (:pointer (:struct point))))

(cffi:defcfun (set-window-context-help-id "SetWindowContextHelpId" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (dword :ulong))

(cffi:defcfun (get-window-context-help-id "GetWindowContextHelpId" :convention :stdcall :library "user32.dll")
    :ulong
    (hwnd :handle))

(cffi:defcfun (set-menu-context-help-id "SetMenuContextHelpId" :convention :stdcall :library "user32.dll")
    :int
    (hmenu :handle)
    (dword :ulong))

(cffi:defcfun (get-menu-context-help-id "GetMenuContextHelpId" :convention :stdcall :library "user32.dll")
    :ulong
    (hmenu :handle))

(cffi:defcstruct msgboxparamsa
  (cb-size :uint)
  (hwnd-owner :handle)
  (h-instance :handle)
  (lpsz-text (:string :encoding :ascii))
  (lpsz-caption (:string :encoding :ascii))
  (dw-style :ulong)
  (lpsz-icon (:string :encoding :ascii))
  (dw-context-help-id :uint64)
  (lpfn-msg-box-callback (:pointer (:struct msgboxcallback)))
  (dw-language-id :ulong))

(cffi:defcstruct msgboxparamsw
  (cb-size :uint)
  (hwnd-owner :handle)
  (h-instance :handle)
  (lpsz-text (:string :encoding :utf-16le))
  (lpsz-caption (:string :encoding :utf-16le))
  (dw-style :ulong)
  (lpsz-icon (:string :encoding :utf-16le))
  (dw-context-help-id :uint64)
  (lpfn-msg-box-callback (:pointer (:struct msgboxcallback)))
  (dw-language-id :ulong))

(cffi:defcfun (message-box-indirect "MessageBoxIndirectW" :convention :stdcall :library "user32.dll")
    :int
    (lpmbp (:pointer (:struct msgboxparamsw))))

(cffi:defcfun (message-beep "MessageBeep" :convention :stdcall :library "user32.dll")
    :int
    (u-type :uint))

(cffi:defcfun (show-cursor "ShowCursor" :convention :stdcall :library "user32.dll")
    :int
    (b-show :int))

(cffi:defcfun (set-cursor-pos "SetCursorPos" :convention :stdcall :library "user32.dll")
    :int
    (x :int)
    (y :int))

(cffi:defcfun (set-physical-cursor-pos "SetPhysicalCursorPos" :convention :stdcall :library "user32.dll")
    :int
    (x :int)
    (y :int))

(cffi:defcfun (set-cursor "SetCursor" :convention :stdcall :library "user32.dll")
    :handle
    (h-cursor :handle))

(cffi:defcfun (get-cursor-pos "GetCursorPos" :convention :stdcall :library "user32.dll")
    :int
    (lp-point (:pointer (:struct lppoint))))

(cffi:defcfun (get-physical-cursor-pos "GetPhysicalCursorPos" :convention :stdcall :library "user32.dll")
    :int
    (lp-point (:pointer (:struct lppoint))))

(cffi:defcfun (clip-cursor "ClipCursor" :convention :stdcall :library "user32.dll")
    :int
    (lp-rect (:pointer (:struct rect))))

(cffi:defcfun (get-clip-cursor "GetClipCursor" :convention :stdcall :library "user32.dll")
    :int
    (lp-rect (:pointer (:struct lprect))))

(cffi:defcfun (get-cursor "GetCursor" :convention :stdcall :library "user32.dll")
    :handle
    (void :void))

(cffi:defcfun (create-caret "CreateCaret" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (h-bitmap :handle)
    (n-width :int)
    (n-height :int))

(cffi:defcfun (get-caret-blink-time "GetCaretBlinkTime" :convention :stdcall :library "user32.dll")
    :uint
    (void :void))

(cffi:defcfun (set-caret-blink-time "SetCaretBlinkTime" :convention :stdcall :library "user32.dll")
    :int
    (u-m-seconds :uint))

(cffi:defcfun (destroy-caret "DestroyCaret" :convention :stdcall :library "user32.dll")
    :int
    (void :void))

(cffi:defcfun (hide-caret "HideCaret" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

(cffi:defcfun (show-caret "ShowCaret" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

(cffi:defcfun (set-caret-pos "SetCaretPos" :convention :stdcall :library "user32.dll")
    :int
    (x :int)
    (y :int))

(cffi:defcfun (get-caret-pos "GetCaretPos" :convention :stdcall :library "user32.dll")
    :int
    (lp-point (:pointer (:struct lppoint))))

(cffi:defcfun (client-to-screen "ClientToScreen" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lp-point (:pointer (:struct lppoint))))

(cffi:defcfun (screen-to-client "ScreenToClient" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lp-point (:pointer (:struct lppoint))))

(cffi:defcfun (logical-to-physical-point "LogicalToPhysicalPoint" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lp-point (:pointer (:struct lppoint))))

(cffi:defcfun (physical-to-logical-point "PhysicalToLogicalPoint" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (lp-point (:pointer (:struct lppoint))))

(cffi:defcfun (map-window-points "MapWindowPoints" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd-from :handle)
    (h-wnd-to :handle)
    (lp-points (:pointer (:struct lppoint)))
    (c-points :uint))

(cffi:defcfun (window-from-point "WindowFromPoint" :convention :stdcall :library "user32.dll")
    :handle
    (point (:pointer (:struct point))))

(cffi:defcfun (window-from-physical-point "WindowFromPhysicalPoint" :convention :stdcall :library "user32.dll")
    :handle
    (point (:pointer (:struct point))))

(cffi:defcfun (child-window-from-point "ChildWindowFromPoint" :convention :stdcall :library "user32.dll")
    :handle
    (h-wnd-parent :handle)
    (point (:pointer (:struct point))))

(cffi:defcfun (child-window-from-point-ex "ChildWindowFromPointEx" :convention :stdcall :library "user32.dll")
    :handle
    (hwnd :handle)
    (pt (:pointer (:struct point)))
    (flags :uint))

(cffi:defcfun (get-sys-color "GetSysColor" :convention :stdcall :library "user32.dll")
    :ulong
    (n-index :int))

(cffi:defcfun (get-sys-color-brush "GetSysColorBrush" :convention :stdcall :library "user32.dll")
    :handle
    (n-index :int))

(cffi:defcfun (set-sys-colors "SetSysColors" :convention :stdcall :library "user32.dll")
    :int
    (c-elements :int)
    (lpa-elements :int)
    (lpa-rgb-values :int32))

(cffi:defcfun (draw-focus-rect "DrawFocusRect" :convention :stdcall :library "user32.dll")
    :int
    (h-dc :handle)
    (lprc (:pointer (:struct rect))))

(cffi:defcfun (fill-rect "FillRect" :convention :stdcall :library "user32.dll")
    :int
    (h-dc :handle)
    (lprc (:pointer (:struct rect)))
    (hbr :handle))

(cffi:defcfun (frame-rect "FrameRect" :convention :stdcall :library "user32.dll")
    :int
    (h-dc :handle)
    (lprc (:pointer (:struct rect)))
    (hbr :handle))

(cffi:defcfun (invert-rect "InvertRect" :convention :stdcall :library "user32.dll")
    :int
    (h-dc :handle)
    (lprc (:pointer (:struct rect))))

(cffi:defcfun (set-rect "SetRect" :convention :stdcall :library "user32.dll")
    :int
    (lprc (:pointer (:struct lprect)))
    (x-left :int)
    (y-top :int)
    (x-right :int)
    (y-bottom :int))

(cffi:defcfun (set-rect-empty "SetRectEmpty" :convention :stdcall :library "user32.dll")
    :int
    (lprc (:pointer (:struct lprect))))

(cffi:defcfun (copy-rect "CopyRect" :convention :stdcall :library "user32.dll")
    :int
    (lprc-dst (:pointer (:struct lprect)))
    (lprc-src (:pointer (:struct rect))))

(cffi:defcfun (inflate-rect "InflateRect" :convention :stdcall :library "user32.dll")
    :int
    (lprc (:pointer (:struct lprect)))
    (dx :int)
    (dy :int))

(cffi:defcfun (intersect-rect "IntersectRect" :convention :stdcall :library "user32.dll")
    :int
    (lprc-dst (:pointer (:struct lprect)))
    (lprc-src1 (:pointer (:struct rect)))
    (lprc-src2 (:pointer (:struct rect))))

(cffi:defcfun (union-rect "UnionRect" :convention :stdcall :library "user32.dll")
    :int
    (lprc-dst (:pointer (:struct lprect)))
    (lprc-src1 (:pointer (:struct rect)))
    (lprc-src2 (:pointer (:struct rect))))

(cffi:defcfun (subtract-rect "SubtractRect" :convention :stdcall :library "user32.dll")
    :int
    (lprc-dst (:pointer (:struct lprect)))
    (lprc-src1 (:pointer (:struct rect)))
    (lprc-src2 (:pointer (:struct rect))))

(cffi:defcfun (offset-rect "OffsetRect" :convention :stdcall :library "user32.dll")
    :int
    (lprc (:pointer (:struct lprect)))
    (dx :int)
    (dy :int))

(cffi:defcfun (is-rect-empty "IsRectEmpty" :convention :stdcall :library "user32.dll")
    :int
    (lprc (:pointer (:struct rect))))

(cffi:defcfun (equal-rect "EqualRect" :convention :stdcall :library "user32.dll")
    :int
    (lprc1 (:pointer (:struct rect)))
    (lprc2 (:pointer (:struct rect))))

(cffi:defcfun (pt-in-rect "PtInRect" :convention :stdcall :library "user32.dll")
    :int
    (lprc (:pointer (:struct rect)))
    (pt (:pointer (:struct point))))

(cffi:defcfun (get-window-word "GetWindowWord" :convention :stdcall :library "user32.dll")
    :ushort
    (h-wnd :handle)
    (n-index :int))

(cffi:defcfun (set-window-word "SetWindowWord" :convention :stdcall :library "user32.dll")
    :ushort
    (h-wnd :handle)
    (n-index :int)
    (w-new-word :ushort))

(cffi:defcfun (get-window-long "GetWindowLongW" :convention :stdcall :library "user32.dll")
    :long
    (h-wnd :handle)
    (n-index :int))

(cffi:defcfun (set-window-long "SetWindowLongW" :convention :stdcall :library "user32.dll")
    :long
    (h-wnd :handle)
    (n-index :int)
    (dw-new-long :long))

(cffi:defcfun (get-window-long-ptr "GetWindowLongPtrW" :convention :stdcall :library "user32.dll")
    :long
    (h-wnd :handle)
    (n-index :int))

(cffi:defcfun (set-window-long-ptr "SetWindowLongPtrW" :convention :stdcall :library "user32.dll")
    :long
    (h-wnd :handle)
    (n-index :int)
    (dw-new-long :long))

(cffi:defcfun (get-class-word "GetClassWord" :convention :stdcall :library "user32.dll")
    :ushort
    (h-wnd :handle)
    (n-index :int))

(cffi:defcfun (set-class-word "SetClassWord" :convention :stdcall :library "user32.dll")
    :ushort
    (h-wnd :handle)
    (n-index :int)
    (w-new-word :ushort))

(cffi:defcfun (get-class-long "GetClassLongW" :convention :stdcall :library "user32.dll")
    :ulong
    (h-wnd :handle)
    (n-index :int))

(cffi:defcfun (set-class-long "SetClassLongW" :convention :stdcall :library "user32.dll")
    :ulong
    (h-wnd :handle)
    (n-index :int)
    (dw-new-long :long))

(cffi:defcfun (get-class-long-ptr "GetClassLongPtrW" :convention :stdcall :library "user32.dll")
    :uint64
    (h-wnd :handle)
    (n-index :int))

(cffi:defcfun (set-class-long-ptr "SetClassLongPtrW" :convention :stdcall :library "user32.dll")
    :uint64
    (h-wnd :handle)
    (n-index :int)
    (dw-new-long :long))

(cffi:defcfun (get-process-default-layout "GetProcessDefaultLayout" :convention :stdcall :library "user32.dll")
    :int
    (pdw-default-layout :ulong))

(cffi:defcfun (set-process-default-layout "SetProcessDefaultLayout" :convention :stdcall :library "user32.dll")
    :int
    (dw-default-layout :ulong))

(cffi:defcfun (get-desktop-windo "GetDesktopWindow" :convention :stdcall :library "user32.dll")
    :handle
    (void :void))

(cffi:defcfun (get-parent "GetParent" :convention :stdcall :library "user32.dll")
    :handle
    (h-wnd :handle))

(cffi:defcfun (set-parent "SetParent" :convention :stdcall :library "user32.dll")
    :handle
    (h-wnd-child :handle)
    (h-wnd-new-parent :handle))

(cffi:defcfun (enum-child-windows "EnumChildWindows" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd-parent :handle)
    (lp-enum-func (:pointer (:struct wndenumproc)))
    (l-param :long))

(cffi:defcfun (find-windo "FindWindowW" :convention :stdcall :library "user32.dll")
    :handle
    (lp-class-name (:string :encoding :utf-16le))
    (lp-window-name (:string :encoding :utf-16le)))

(cffi:defcfun (find-window-ex "FindWindowExW" :convention :stdcall :library "user32.dll")
    :handle
    (h-wnd-parent :handle)
    (h-wnd-child-after :handle)
    (lpsz-class (:string :encoding :utf-16le))
    (lpsz-window (:string :encoding :utf-16le)))

(cffi:defcfun (get-shell-windo "GetShellWindow" :convention :stdcall :library "user32.dll")
    :handle
    (void :void))

(cffi:defcfun (register-shell-hook-windo "RegisterShellHookWindow" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle))

(cffi:defcfun (deregister-shell-hook-windo "DeregisterShellHookWindow" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle))

(cffi:defcfun (enum-windows "EnumWindows" :convention :stdcall :library "user32.dll")
    :int
    (lp-enum-func (:pointer (:struct wndenumproc)))
    (l-param :long))

(cffi:defcfun (enum-thread-windows "EnumThreadWindows" :convention :stdcall :library "user32.dll")
    :int
    (dw-thread-id :ulong)
    (lpfn (:pointer (:struct wndenumproc)))
    (l-param :long))

(cffi:defcfun (get-class-name "GetClassNameW" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (n-max-count :int))

(cffi:defcfun (get-top-windo "GetTopWindow" :convention :stdcall :library "user32.dll")
    :handle
    (h-wnd :handle))

(cffi:defcfun (get-window-thread-process-id "GetWindowThreadProcessId" :convention :stdcall :library "user32.dll")
    :ulong
    (h-wnd :handle)
    (lpdw-process-id (:pointer :int32)))

(cffi:defcfun (is-gui-thread "IsGUIThread" :convention :stdcall :library "user32.dll")
    :int
    (b-convert :int))

(cffi:defcfun (get-last-active-popup "GetLastActivePopup" :convention :stdcall :library "user32.dll")
    :handle
    (h-wnd :handle))

(cffi:defcfun (get-windo "GetWindow" :convention :stdcall :library "user32.dll")
    :handle
    (h-wnd :handle)
    (u-cmd :uint))

(cffi:defcfun (set-windows-hook "SetWindowsHookW" :convention :stdcall :library "user32.dll")
    :handle
    (n-filter-type :int)
    (pfn-filter-proc (:pointer (:struct hookproc))))

(cffi:defcfun (set-windows-hook "SetWindowsHookW" :convention :stdcall :library "user32.dll")
    :HOOKPROC
    (n-filter-type :int)
    (pfn-filter-proc (:pointer (:struct hookproc))))

(cffi:defcfun (unhook-windows-hook "UnhookWindowsHook" :convention :stdcall :library "user32.dll")
    :int
    (n-code :int)
    (pfn-filter-proc (:pointer (:struct hookproc))))

(cffi:defcfun (set-windows-hook-ex "SetWindowsHookExW" :convention :stdcall :library "user32.dll")
    :handle
    (id-hook :int)
    (lpfn (:pointer (:struct hookproc)))
    (hmod :handle)
    (dw-thread-id :ulong))

(cffi:defcfun (unhook-windows-hook-ex "UnhookWindowsHookEx" :convention :stdcall :library "user32.dll")
    :int
    (hhk :handle))

(cffi:defcfun (call-next-hook-ex "CallNextHookEx" :convention :stdcall :library "user32.dll")
    :int64
    (hhk :handle)
    (n-code :int)
    (w-param :uint64)
    (l-param :long))

(cffi:defcfun (check-menu-radio-item "CheckMenuRadioItem" :convention :stdcall :library "user32.dll")
    :int
    (hmenu :handle)
    (first :uint)
    (last :uint)
    (check :uint)
    (flags :uint))

(cffi:defcfun (load-bitmap "LoadBitmapW" :convention :stdcall :library "user32.dll")
    :handle
    (h-instance :handle)
    (lp-bitmap-name (:string :encoding :utf-16le)))

(cffi:defcfun (load-cursor "LoadCursorW" :convention :stdcall :library "user32.dll")
    :handle
    (h-instance :handle)
    (lp-cursor-name (:string :encoding :utf-16le)))

(cffi:defcfun (load-cursor-from-file "LoadCursorFromFileW" :convention :stdcall :library "user32.dll")
    :handle
    (lp-file-name (:string :encoding :utf-16le)))

(cffi:defcfun (create-cursor "CreateCursor" :convention :stdcall :library "user32.dll")
    :handle
    (h-inst :handle)
    (x-hot-spot :int)
    (y-hot-spot :int)
    (n-width :int)
    (n-height :int)
    (pv-and-plane :void)
    (pv-xor-plane :void))

(cffi:defcfun (destroy-cursor "DestroyCursor" :convention :stdcall :library "user32.dll")
    :int
    (h-cursor :handle))

(cffi:defcfun (copy-cursor "CopyCursor" :convention :stdcall :library "user32.dll")
    :handle
    (h-cursor :handle))

(cffi:defcfun (set-system-cursor "SetSystemCursor" :convention :stdcall :library "user32.dll")
    :int
    (hcur :handle)
    (id :ulong))

(cffi:defcfun (load-icon "LoadIconW" :convention :stdcall :library "user32.dll")
    :handle
    (h-instance :handle)
    (lp-icon-name (:string :encoding :utf-16le)))

(cffi:defcfun (private-extract-icons "PrivateExtractIconsW" :convention :stdcall :library "user32.dll")
    :uint
    (sz-file-name (:string :encoding :utf-16le))
    (n-icon-index :int)
    (cx-icon :int)
    (cy-icon :int)
    (n-icons :uint)
    (flags :uint))

(cffi:defcfun (create-icon "CreateIcon" :convention :stdcall :library "user32.dll")
    :handle
    (h-instance :handle)
    (n-width :int)
    (n-height :int)
    (c-planes :uchar)
    (c-bits-pixel :uchar)
    (lpb-an-dbits :uchar)
    (lpb-xo-rbits :uchar))

(cffi:defcfun (destroy-icon "DestroyIcon" :convention :stdcall :library "user32.dll")
    :int
    (h-icon :handle))

(cffi:defcfun (lookup-icon-id-from-directory "LookupIconIdFromDirectory" :convention :stdcall :library "user32.dll")
    :int
    (presbits (:pointer :int8))
    (f-icon :int))

(cffi:defcfun (lookup-icon-id-from-directory-ex "LookupIconIdFromDirectoryEx" :convention :stdcall :library "user32.dll")
    :int
    (presbits (:pointer :int8))
    (f-icon :int)
    (cx-desired :int)
    (cy-desired :int)
    (flags :uint))

(cffi:defcfun (create-icon-from-resource "CreateIconFromResource" :convention :stdcall :library "user32.dll")
    :handle
    (presbits (:pointer :int8))
    (dw-res-size :ulong)
    (f-icon :int)
    (dw-ver :ulong))

(cffi:defcfun (create-icon-from-resource-ex "CreateIconFromResourceEx" :convention :stdcall :library "user32.dll")
    :handle
    (presbits (:pointer :int8))
    (dw-res-size :ulong)
    (f-icon :int)
    (dw-ver :ulong)
    (cx-desired :int)
    (cy-desired :int)
    (flags :uint))

(cffi:defcstruct cursorshape
  (x-hot-spot :int)
  (y-hot-spot :int)
  (cx :int)
  (cy :int)
  (cb-width :int)
  (planes :uchar)
  (bits-pixel :uchar))

(cffi:defcfun (load-image "LoadImageW" :convention :stdcall :library "user32.dll")
    :int64
    (h-inst :handle)
    (name (:string :encoding :utf-16le))
    (type :uint)
    (cx :int)
    (cy :int)
    (fu-load :uint))

(cffi:defcfun (copy-image "CopyImage" :convention :stdcall :library "user32.dll")
    :int64
    (h :int64)
    (type :uint)
    (cx :int)
    (cy :int)
    (flags :uint))

(cffi:defcfun (int "int" :convention :stdcall :library "user32.dll")
    :handle
    (h-icon :handle)
    (cx-width :int)
    (cy-width :int)
    (istep-if-ani-cur :uint)
    (hbr-flicker-free-draw :handle)
    (di-flags :uint))

(cffi:defcfun (create-icon-indirect "CreateIconIndirect" :convention :stdcall :library "user32.dll")
    :handle
    (piconinfo (:pointer (:struct piconinfo))))

(cffi:defcfun (copy-icon "CopyIcon" :convention :stdcall :library "user32.dll")
    :handle
    (h-icon :handle))

(cffi:defcfun (get-icon-info "GetIconInfo" :convention :stdcall :library "user32.dll")
    :int
    (h-icon :handle)
    (piconinfo (:pointer (:struct piconinfo))))

(cffi:defcfun (get-icon-info-ex "GetIconInfoExW" :convention :stdcall :library "user32.dll")
    :int
    (hicon :handle)
    (piconinfo (:pointer (:struct piconinfoexw))))

(cffi:defcfun (load-string "LoadStringW" :convention :stdcall :library "user32.dll")
    :int
    (h-instance :handle)
    (u-id :uint)
    (cch-buffer-max :int))

(cffi:defcfun (is-dialog-message "IsDialogMessageW" :convention :stdcall :library "user32.dll")
    :int
    (h-dlg :handle)
    (lp-msg (:pointer (:struct lpmsg))))

(cffi:defcfun (map-dialog-rect "MapDialogRect" :convention :stdcall :library "user32.dll")
    :int
    (h-dlg :handle)
    (lp-rect (:pointer (:struct lprect))))

(cffi:defcfun (dlg-dir-list "DlgDirListW" :convention :stdcall :library "user32.dll")
    :int
    (h-dlg :handle)
    (lp-path-spec (:string :encoding :utf-16le))
    (n-id-list-box :int)
    (n-id-static-path :int)
    (u-file-type :uint))

(cffi:defcfun (dlg-dir-select-ex "DlgDirSelectExW" :convention :stdcall :library "user32.dll")
    :int
    (hwnd-dlg :handle)
    (lp-string (:string :encoding :utf-16le))
    (ch-count :int)
    (id-list-box :int))

(cffi:defcfun (dlg-dir-list-combo-box "DlgDirListComboBoxW" :convention :stdcall :library "user32.dll")
    :int
    (h-dlg :handle)
    (lp-path-spec (:string :encoding :utf-16le))
    (n-id-combo-box :int)
    (n-id-static-path :int)
    (u-filetype :uint))

(cffi:defcfun (dlg-dir-select-combo-box-ex "DlgDirSelectComboBoxExW" :convention :stdcall :library "user32.dll")
    :int
    (hwnd-dlg :handle)
    (lp-string (:string :encoding :utf-16le))
    (cch-out :int)
    (id-combo-box :int))

(cffi:defcstruct scrollinfo
  (cb-size :uint)
  (f-mask :uint)
  (n-min :int)
  (n-max :int)
  (n-page :uint)
  (n-pos :int)
  (n-track-pos :int))

(cffi:defcfun (set-scroll-info "SetScrollInfo" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (n-bar :int)
    (lpsi (:pointer (:struct lpcscrollinfo)))
    (redraw :int))

(cffi:defcfun (get-scroll-info "GetScrollInfo" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (n-bar :int)
    (lpsi (:pointer (:struct lpscrollinfo))))

(cffi:defcstruct mdicreatestructa
  (sz-class (:string :encoding :ascii))
  (sz-title (:string :encoding :ascii))
  (h-owner :int64)
  (x :int)
  (y :int)
  (cx :int)
  (cy :int)
  (style :ulong)
  (l-param :long))

(cffi:defcstruct mdicreatestructw
  (sz-class (:string :encoding :utf-16le))
  (sz-title (:string :encoding :utf-16le))
  (h-owner :int64)
  (x :int)
  (y :int)
  (cx :int)
  (cy :int)
  (style :ulong)
  (l-param :long))

(cffi:defcstruct clientcreatestruct
  (h-window-menu :int64)
  (id-first-child :uint))

(cffi:defcfun (def-frame-proc "DefFrameProcW" :convention :stdcall :library "user32.dll")
    :int64
    (h-wnd :handle)
    (h-wnd-mdi-client :handle)
    (u-msg :uint)
    (w-param :uint64)
    (l-param :long))

(cffi:defcfun (def-mdi-child-proc "DefMDIChildProcW" :convention :stdcall :library "user32.dll")
    :int64
    (h-wnd :handle)
    (u-msg :uint)
    (w-param :uint64)
    (l-param :long))

(cffi:defcfun (translate-mdi-sys-accel "TranslateMDISysAccel" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd-client :handle)
    (lp-msg (:pointer (:struct lpmsg))))

(cffi:defcfun (arrange-iconic-windows "ArrangeIconicWindows" :convention :stdcall :library "user32.dll")
    :uint
    (h-wnd :handle))

(cffi:defcfun (create-mdi-windo "CreateMDIWindowW" :convention :stdcall :library "user32.dll")
    :handle
    (lp-class-name (:string :encoding :utf-16le))
    (lp-window-name (:string :encoding :utf-16le))
    (dw-style :ulong)
    (x :int)
    (y :int)
    (n-width :int)
    (n-height :int)
    (h-wnd-parent :handle)
    (h-instance :handle)
    (l-param :long))

(cffi:defcfun (tile-windows "TileWindows" :convention :stdcall :library "user32.dll")
    :ushort
    (hwnd-parent :handle)
    (w-how :uint)
    (lp-rect (:pointer (:struct rect)))
    (c-kids :uint)
    (lp-kids (:pointer (:struct far))))

(cffi:defcfun (hwnd "HWND" :convention :stdcall :library "user32.dll")
    :ushort
    (w-how :uint)
    (lp-rect (:pointer (:struct rect)))
    (c-kids :uint)
    (lp-kids (:pointer (:struct far))))

(cffi:defcstruct multikeyhelpa
  (mk-size :ushort)
  (mk-keylist :char)
  (sz-keyphrase[1] :char))

(cffi:defcstruct multikeyhelpw
  (mk-size :ushort)
  (mk-keylist :wchar)
  (sz-keyphrase[1] :wchar))

(cffi:defcstruct helpwininfoa
  (w-struct-size :int)
  (x :int)
  (y :int)
  (dx :int)
  (dy :int)
  (w-max :int)
  (rgch-member[2] :char))

(cffi:defcstruct helpwininfow
  (w-struct-size :int)
  (x :int)
  (y :int)
  (dx :int)
  (dy :int)
  (w-max :int)
  (rgch-member[2] :wchar))

(cffi:defcfun (win-help "WinHelpW" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd-main :handle)
    (lpsz-help (:string :encoding :utf-16le))
    (u-command :uint)
    (dw-data :uint64))

(cffi:defcfun (get-gui-resources "GetGuiResources" :convention :stdcall :library "user32.dll")
    :ulong
    (h-process :int64)
    (ui-flags :ulong))

(cffi:defcstruct nonclientmetricsa
  (cb-size :uint)
  (i-border-width :int)
  (i-scroll-width :int)
  (i-scroll-height :int)
  (i-caption-width :int)
  (i-caption-height :int)
  (lf-caption-font (:pointer (:struct logfonta)))
  (i-sm-caption-width :int)
  (i-sm-caption-height :int)
  (lf-sm-caption-font (:pointer (:struct logfonta)))
  (i-menu-width :int)
  (i-menu-height :int)
  (lf-menu-font (:pointer (:struct logfonta)))
  (lf-status-font (:pointer (:struct logfonta)))
  (lf-message-font (:pointer (:struct logfonta)))
  (i-padded-border-width :int))

(cffi:defcstruct nonclientmetricsw
  (cb-size :uint)
  (i-border-width :int)
  (i-scroll-width :int)
  (i-scroll-height :int)
  (i-caption-width :int)
  (i-caption-height :int)
  (lf-caption-font (:pointer (:struct logfontw)))
  (i-sm-caption-width :int)
  (i-sm-caption-height :int)
  (lf-sm-caption-font (:pointer (:struct logfontw)))
  (i-menu-width :int)
  (i-menu-height :int)
  (lf-menu-font (:pointer (:struct logfontw)))
  (lf-status-font (:pointer (:struct logfontw)))
  (lf-message-font (:pointer (:struct logfontw)))
  (i-padded-border-width :int))

(cffi:defcstruct minimizedmetrics
  (cb-size :uint)
  (i-width :int)
  (i-horz-gap :int)
  (i-vert-gap :int)
  (i-arrange :int))

(cffi:defcstruct iconmetricsa
  (cb-size :uint)
  (i-horz-spacing :int)
  (i-vert-spacing :int)
  (i-title-wrap :int)
  (lf-font (:pointer (:struct logfonta))))

(cffi:defcstruct iconmetricsw
  (cb-size :uint)
  (i-horz-spacing :int)
  (i-vert-spacing :int)
  (i-title-wrap :int)
  (lf-font (:pointer (:struct logfontw))))

(cffi:defcstruct animationinfo
  (cb-size :uint)
  (i-min-animate :int))

(cffi:defcstruct serialkeysa
  (cb-size :uint)
  (dw-flags :ulong)
  (lpsz-active-port (:pointer :char))
  (lpsz-port (:pointer :char))
  (i-baud-rate :uint)
  (i-port-state :uint)
  (i-active :uint))

(cffi:defcstruct serialkeysw
  (cb-size :uint)
  (dw-flags :ulong)
  (lpsz-active-port (:string :encoding :utf-16le))
  (lpsz-port (:string :encoding :utf-16le))
  (i-baud-rate :uint)
  (i-port-state :uint)
  (i-active :uint))

(cffi:defcstruct highcontrasta
  (cb-size :uint)
  (dw-flags :ulong)
  (lpsz-default-scheme (:pointer :char)))

(cffi:defcstruct highcontrastw
  (cb-size :uint)
  (dw-flags :ulong)
  (lpsz-default-scheme (:string :encoding :utf-16le)))

(cffi:defcfun (change-display-settings "ChangeDisplaySettingsW" :convention :stdcall :library "user32.dll")
    :long
    (lp-dev-mode (:pointer (:struct devmodew)))
    (dw-flags :ulong))

(cffi:defcfun (change-display-settings-ex "ChangeDisplaySettingsExW" :convention :stdcall :library "user32.dll")
    :long
    (lpsz-device-name (:string :encoding :utf-16le))
    (lp-dev-mode (:pointer (:struct devmodew)))
    (hwnd :handle)
    (dwflags :ulong)
    (l-param (:pointer :void)))

(cffi:defcfun (enum-display-settings "EnumDisplaySettingsW" :convention :stdcall :library "user32.dll")
    :int
    (lpsz-device-name (:string :encoding :utf-16le))
    (i-mode-num :ulong)
    (lp-dev-mode (:pointer (:struct devmodew))))

(cffi:defcfun (enum-display-settings-ex "EnumDisplaySettingsExW" :convention :stdcall :library "user32.dll")
    :int
    (lpsz-device-name (:string :encoding :utf-16le))
    (i-mode-num :ulong)
    (lp-dev-mode (:pointer (:struct devmodew)))
    (dw-flags :ulong))

(cffi:defcfun (enum-display-devices "EnumDisplayDevicesW" :convention :stdcall :library "user32.dll")
    :int
    (lp-device (:string :encoding :utf-16le))
    (i-dev-num :ulong)
    (lp-display-device (:pointer (:struct pdisplay-devicew)))
    (dw-flags :ulong))

(cffi:defcfun (get-display-config-buffer-sizes "GetDisplayConfigBufferSizes" :convention :stdcall :library "user32.dll")
    :long
    (flags :uint)
    (num-path-array-elements :uint)
    (num-mode-info-array-elements :uint))

(cffi:defcfun (set-display-config "SetDisplayConfig" :convention :stdcall :library "user32.dll")
    :long
    (num-path-array-elements :uint)
    (path-array (:pointer (:struct displayconfig-path-info)))
    (num-mode-info-array-elements :uint)
    (mode-info-array (:pointer (:struct displayconfig-mode-info)))
    (flags :uint))

(cffi:defcfun (query-display-config "QueryDisplayConfig" :convention :stdcall :library "user32.dll")
    :long
    (flags :uint)
    (num-path-array-elements :uint)
    (num-mode-info-array-elements :uint)
    (current-topology-id (:pointer (:struct displayconfig-topology-id))))

(cffi:defcfun (display-config-get-device-info "DisplayConfigGetDeviceInfo" :convention :stdcall :library "user32.dll")
    :long
    (request-packet (:pointer (:struct displayconfig-device-info-header))))

(cffi:defcfun (display-config-set-device-info "DisplayConfigSetDeviceInfo" :convention :stdcall :library "user32.dll")
    :long
    (set-packet (:pointer (:struct displayconfig-device-info-header))))

(cffi:defcfun (system-parameters-info "SystemParametersInfoW" :convention :stdcall :library "user32.dll")
    :int
    (ui-action :uint)
    (ui-param :uint)
    (pv-param (:string :void))
    (f-win-ini :uint))

(cffi:defcstruct filterkeys
  (cb-size :uint)
  (dw-flags :ulong)
  (i-wait-m-sec :ulong)
  (i-delay-m-sec :ulong)
  (i-repeat-m-sec :ulong)
  (i-bounce-m-sec :ulong))

(cffi:defcstruct stickykeys
  (cb-size :uint)
  (dw-flags :ulong))

(cffi:defcstruct mousekeys
  (cb-size :uint)
  (dw-flags :ulong)
  (i-max-speed :ulong)
  (i-time-to-max-speed :ulong)
  (i-ctrl-speed :ulong)
  (dw-reserved1 :ulong)
  (dw-reserved2 :ulong))

(cffi:defcstruct accesstimeout
  (cb-size :uint)
  (dw-flags :ulong)
  (i-time-out-m-sec :ulong))

(cffi:defcstruct soundsentrya
  (cb-size :uint)
  (dw-flags :ulong)
  (i-fs-text-effect :ulong)
  (i-fs-text-effect-m-sec :ulong)
  (i-fs-text-effect-color-bits :ulong)
  (i-fs-graf-effect :ulong)
  (i-fs-graf-effect-m-sec :ulong)
  (i-fs-graf-effect-color :ulong)
  (i-windows-effect :ulong)
  (i-windows-effect-m-sec :ulong)
  (lpsz-windows-effect-dll (:pointer :char))
  (i-windows-effect-ordinal :ulong))

(cffi:defcstruct soundsentryw
  (cb-size :uint)
  (dw-flags :ulong)
  (i-fs-text-effect :ulong)
  (i-fs-text-effect-m-sec :ulong)
  (i-fs-text-effect-color-bits :ulong)
  (i-fs-graf-effect :ulong)
  (i-fs-graf-effect-m-sec :ulong)
  (i-fs-graf-effect-color :ulong)
  (i-windows-effect :ulong)
  (i-windows-effect-m-sec :ulong)
  (lpsz-windows-effect-dll (:string :encoding :utf-16le))
  (i-windows-effect-ordinal :ulong))

(cffi:defcfun (sound-sentry-void "SoundSentryVOID" :convention :stdcall :library "user32.dll")
    :int)

(cffi:defcstruct togglekeys
  (cb-size :uint)
  (dw-flags :ulong))

(cffi:defcstruct audiodescription
  (cb-size :uint)
  (enabled :int)
  (locale :int32))

(cffi:defcfun (set-debug-error-level "SetDebugErrorLevel" :convention :stdcall :library "user32.dll")
    :void
    (dw-level :ulong))

(cffi:defcfun (set-last-error-ex "SetLastErrorEx" :convention :stdcall :library "user32.dll")
    :void
    (dw-err-code :ulong)
    (dw-type :ulong))

(cffi:defcfun (internal-get-window-text "InternalGetWindowText" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (cch-max-count :int))

(cffi:defcfun (end-task "EndTask" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (f-shut-down :int)
    (f-force :int))

(cffi:defcfun (cancel-shutdown "CancelShutdown" :convention :stdcall :library "user32.dll")
    :int
    (void :void))

(cffi:defcfun (monitor-from-point "MonitorFromPoint" :convention :stdcall :library "user32.dll")
    :handle
    (pt (:pointer (:struct point)))
    (dw-flags :ulong))

(cffi:defcfun (monitor-from-rect "MonitorFromRect" :convention :stdcall :library "user32.dll")
    :handle
    (lprc (:pointer (:struct lpcrect)))
    (dw-flags :ulong))

(cffi:defcfun (monitor-from-windo "MonitorFromWindow" :convention :stdcall :library "user32.dll")
    :handle
    (hwnd :handle)
    (dw-flags :ulong))

(cffi:defcstruct monitorinfo
  (cb-size :ulong)
  (rc-monitor (:pointer (:struct rect)))
  (rc-work (:pointer (:struct rect)))
  (dw-flags :ulong))

(cffi:defcstruct monitorinfoexa : public tagmonitorinfo
		(sz-device[-cchdevicenam-e] :char))

(cffi:defcstruct monitorinfoexw : public tagmonitorinfo
		(sz-device[-cchdevicenam-e] :wchar))

(cffi:defcstruct monitorinfoexa
  (monitorinfo (:pointer (:struct monitorinfo)))
  (sz-device[-cchdevicenam-e] :char))

(cffi:defcstruct monitorinfoexw
  (monitorinfo (:pointer (:struct monitorinfo)))
  (sz-device[-cchdevicenam-e] :wchar))

(cffi:defcfun (get-monitor-info "GetMonitorInfoW" :convention :stdcall :library "user32.dll")
    :int
    (h-monitor :handle)
    (lpmi (:pointer (:struct lpmonitorinfo))))

(cffi:defcfun (enum-display-monitors "EnumDisplayMonitors" :convention :stdcall :library "user32.dll")
    :int
    (hdc :handle)
    (lprc-clip (:pointer (:struct lpcrect)))
    (lpfn-enum (:pointer (:struct monitorenumproc)))
    (dw-data :long))

(cffi:defcfun (notify-win-event "NotifyWinEvent" :convention :stdcall :library "user32.dll")
    :void
    (event :ulong)
    (hwnd :handle)
    (id-object :long)
    (id-child :long))

(cffi:defcfun (set-win-event-hook "SetWinEventHook" :convention :stdcall :library "user32.dll")
    :HWINEVENTHOOK
    (event-min :ulong)
    (event-max :ulong)
    (hmod-win-event-proc :handle)
    (pfn-win-event-proc (:pointer (:struct wineventproc)))
    (id-process :ulong)
    (id-thread :ulong)
    (dw-flags :ulong))

(cffi:defcfun (is-win-event-hook-installed "IsWinEventHookInstalled" :convention :stdcall :library "user32.dll")
    :int
    (event :ulong))

(cffi:defcfun (unhook-win-event "UnhookWinEvent" :convention :stdcall :library "user32.dll")
    :int
    (h-win-event-hook (:pointer (:struct hwineventhook))))

(cffi:defcstruct guithreadinfo
  (cb-size :ulong)
  (flags :ulong)
  (hwnd-active :handle)
  (hwnd-focus :handle)
  (hwnd-capture :handle)
  (hwnd-menu-owner :handle)
  (hwnd-move-size :handle)
  (hwnd-caret :handle)
  (rc-caret (:pointer (:struct rect))))

(cffi:defcfun (get-gui-thread-info "GetGUIThreadInfo" :convention :stdcall :library "user32.dll")
    :int
    (id-thread :ulong)
    (pgui (:pointer (:struct pguithreadinfo))))

(cffi:defcfun (block-input "BlockInput" :convention :stdcall :library "user32.dll")
    :int
    (f-block-it :int))

(cffi:defcfun (set-process-dpi-aware "SetProcessDPIAware" :convention :stdcall :library "user32.dll")
    :int
    (void :void))

(cffi:defcfun (is-process-dpi-aware "IsProcessDPIAware" :convention :stdcall :library "user32.dll")
    :int
    (void :void))

(cffi:defcfun (get-window-module-file-name "GetWindowModuleFileNameW" :convention :stdcall :library "user32.dll")
    :uint
    (hwnd :handle)
    (cch-file-name-max :uint))

(cffi:defcstruct cursorinfo
  (cb-size :ulong)
  (flags :ulong)
  (h-cursor :handle)
  (pt-screen-pos (:pointer (:struct point))))

(cffi:defcfun (get-cursor-info "GetCursorInfo" :convention :stdcall :library "user32.dll")
    :int
    (pci (:pointer (:struct pcursorinfo))))

(cffi:defcstruct windowinfo
  (cb-size :ulong)
  (rc-window (:pointer (:struct rect)))
  (rc-client (:pointer (:struct rect)))
  (dw-style :ulong)
  (dw-ex-style :ulong)
  (dw-window-status :ulong)
  (cx-window-borders :uint)
  (cy-window-borders :uint)
  (atom-window-type :int16)
  (w-creator-version :ushort))

(cffi:defcfun (get-window-info "GetWindowInfo" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (pwi (:pointer (:struct pwindowinfo))))

(cffi:defcstruct titlebarinfo
  (cb-size :ulong)
  (rc-title-bar (:pointer (:struct rect)))
  (1] (:pointer (:struct +))))

(cffi:defcfun (get-title-bar-info "GetTitleBarInfo" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (pti (:pointer (:struct ptitlebarinfo))))

(cffi:defcstruct titlebarinfoex
  (cb-size :ulong)
  (rc-title-bar (:pointer (:struct rect)))
  (1] (:pointer (:struct +)))
  (1] (:pointer (:struct +))))

(cffi:defcstruct menubarinfo
  (cb-size :ulong)
  (rc-bar (:pointer (:struct rect)))
  (h-menu :handle)
  (hwnd-menu :handle)
  (f-bar-focused:1 :int)
  (f-focused:1 :int))

(cffi:defcfun (get-menu-bar-info "GetMenuBarInfo" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (id-object :long)
    (id-item :long)
    (pmbi (:pointer (:struct pmenubarinfo))))

(cffi:defcstruct scrollbarinfo
  (cb-size :ulong)
  (rc-scroll-bar (:pointer (:struct rect)))
  (dxy-line-button :int)
  (xy-thumb-top :int)
  (xy-thumb-bottom :int)
  (reserved :int)
  (1] (:pointer (:struct +))))

(cffi:defcfun (get-scroll-bar-info "GetScrollBarInfo" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (id-object :long)
    (psbi (:pointer (:struct pscrollbarinfo))))

(cffi:defcstruct comboboxinfo
  (cb-size :ulong)
  (rc-item (:pointer (:struct rect)))
  (rc-button (:pointer (:struct rect)))
  (state-button :ulong)
  (hwnd-combo :handle)
  (hwnd-item :handle)
  (hwnd-list :handle))

(cffi:defcfun (get-combo-box-info "GetComboBoxInfo" :convention :stdcall :library "user32.dll")
    :int
    (hwnd-combo :handle)
    (pcbi (:pointer (:struct pcomboboxinfo))))

(cffi:defcfun (get-ancestor "GetAncestor" :convention :stdcall :library "user32.dll")
    :handle
    (hwnd :handle)
    (ga-flags :uint))

(cffi:defcfun (real-child-window-from-point "RealChildWindowFromPoint" :convention :stdcall :library "user32.dll")
    :handle
    (hwnd-parent :handle)
    (pt-parent-client-coords (:pointer (:struct point))))

(cffi:defcfun (real-get-window-class "RealGetWindowClassW" :convention :stdcall :library "user32.dll")
    :uint
    (hwnd :handle)
    (cch-class-name-max :uint))

(cffi:defcstruct alttabinfo
  (cb-size :ulong)
  (c-items :int)
  (c-columns :int)
  (c-rows :int)
  (i-col-focus :int)
  (i-row-focus :int)
  (cx-item :int)
  (cy-item :int)
  (pt-start (:pointer (:struct point))))

(cffi:defcfun (get-alt-tab-info "GetAltTabInfoW" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (i-item :int)
    (pati (:pointer (:struct palttabinfo)))
    (psz-item-text (:string :encoding :utf-16le))
    (cch-item-text :uint))

(cffi:defcfun (get-list-box-info "GetListBoxInfo" :convention :stdcall :library "user32.dll")
    :ulong
    (hwnd :handle))

(cffi:defcfun (lock-work-station "LockWorkStation" :convention :stdcall :library "user32.dll")
    :int
    (void :void))

(cffi:defcfun (user-handle-grant-access "UserHandleGrantAccess" :convention :stdcall :library "user32.dll")
    :int
    (h-user-handle :int64)
    (h-job :int64)
    (b-grant :int))

(cffi:defcstruct rawinputheader
  (dw-type :ulong)
  (dw-size :ulong)
  (h-device :int64)
  (w-param :uint64))

(cffi:defcstruct rawmouse
  (us-flags :ushort)
  (ul-buttons :ulong)
  (us-button-flags :ushort)
  (us-button-data :ushort)
  (ul-raw-buttons :ulong)
  (l-last-x :long)
  (l-last-y :long)
  (ul-extra-information :ulong))

(cffi:defcstruct rawkeyboard
  (make-code :ushort)
  (flags :ushort)
  (reserved :ushort)
  (v-key :ushort)
  (message :uint)
  (extra-information :ulong))

(cffi:defcstruct rawhid
  (dw-size-hid :ulong)
  (dw-count :ulong)
  (b-raw-data[1] :uchar))

(cffi:defcstruct rawinput
  (header (:pointer (:struct rawinputheader)))
  (mouse (:pointer (:struct rawmouse)))
  (keyboard (:pointer (:struct rawkeyboard)))
  (hid (:pointer (:struct rawhid))))

(cffi:defcfun (get-raw-input-data "GetRawInputData" :convention :stdcall :library "user32.dll")
    :uint
    (h-raw-input (:pointer (:struct hrawinput)))
    (ui-command :uint)
    (pcb-size (:pointer :uint))
    (cb-size-header :uint))

(cffi:defcstruct rid-device-info-mouse
  (dw-id :ulong)
  (dw-number-of-buttons :ulong)
  (dw-sample-rate :ulong)
  (f-has-horizontal-wheel :int))

(cffi:defcstruct rid-device-info-keyboard
  (dw-type :ulong)
  (dw-sub-type :ulong)
  (dw-keyboard-mode :ulong)
  (dw-number-of-function-keys :ulong)
  (dw-number-of-indicators :ulong)
  (dw-number-of-keys-total :ulong))

(cffi:defcstruct rid-device-info-hid
  (dw-vendor-id :ulong)
  (dw-product-id :ulong)
  (dw-version-number :ulong)
  (us-usage-page :ushort)
  (us-usage :ushort))

(cffi:defcstruct rid-device-info
  (cb-size :ulong)
  (dw-type :ulong)
  (mouse (:pointer (:struct rid-device-info-mouse)))
  (keyboard (:pointer (:struct rid-device-info-keyboard)))
  (hid (:pointer (:struct rid-device-info-hid))))

(cffi:defcfun (get-raw-input-device-info "GetRawInputDeviceInfoW" :convention :stdcall :library "user32.dll")
    :uint
    (h-device :int64)
    (ui-command :uint)
    (pcb-size (:pointer :uint)))

(cffi:defcfun (get-raw-input-buffer "GetRawInputBuffer" :convention :stdcall :library "user32.dll")
    :uint
    (p-data (:pointer (:struct prawinput)))
    (pcb-size (:pointer :uint))
    (cb-size-header :uint))

(cffi:defcstruct rawinputdevice
  (us-usage-page :ushort)
  (us-usage :ushort)
  (dw-flags :ulong)
  (hwnd-target :handle))

(cffi:defcfun (register-raw-input-devices "RegisterRawInputDevices" :convention :stdcall :library "user32.dll")
    :int
    (p-raw-input-devices (:pointer (:struct pcrawinputdevice)))
    (ui-num-devices :uint)
    (cb-size :uint))

(cffi:defcfun (get-registered-raw-input-devices "GetRegisteredRawInputDevices" :convention :stdcall :library "user32.dll")
    :uint
    (p-raw-input-devices (:pointer (:struct prawinputdevice)))
    (pui-num-devices (:pointer :uint))
    (cb-size :uint))

(cffi:defcstruct rawinputdevicelist
  (h-device :int64)
  (dw-type :ulong))

(cffi:defcfun (get-raw-input-device-list "GetRawInputDeviceList" :convention :stdcall :library "user32.dll")
    :uint
    (p-raw-input-device-list (:pointer (:struct prawinputdevicelist)))
    (pui-num-devices (:pointer :uint))
    (cb-size :uint))

(cffi:defcfun (def-raw-input-proc "DefRawInputProc" :convention :stdcall :library "user32.dll")
    :int64
    (pa-raw-input (:pointer (:struct prawinput)))
    (n-input :int)
    (cb-size-header :uint))

(cffi:defcfun (change-window-message-filter "ChangeWindowMessageFilter" :convention :stdcall :library "user32.dll")
    :int
    (message :uint)
    (dw-flag :ulong))

(cffi:defcstruct changefilterstruct
  (cb-size :ulong)
  (ext-status :ulong))

(cffi:defcfun (change-window-message-filter-ex "ChangeWindowMessageFilterEx" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (message :uint)
    (action :ulong)
    (p-change-filter-struct (:pointer (:struct pchangefilterstruct))))

(cffi:defcstruct gestureinfo
  (cb-size :uint)
  (dw-flags :ulong)
  (dw-id :ulong)
  (hwnd-target :handle)
  (pts-location (:pointer (:struct points)))
  (dw-instance-id :ulong)
  (dw-sequence-id :ulong)
  (ull-arguments :uint64)
  (cb-extra-args :uint))

(cffi:defcstruct gesturenotifystruct
  (cb-size :uint)
  (dw-flags :ulong)
  (hwnd-target :handle)
  (pts-location (:pointer (:struct points)))
  (dw-instance-id :ulong))

(cffi:defcfun (get-gesture-info "GetGestureInfo" :convention :stdcall :library "user32.dll")
    :int
    (h-gesture-info (:pointer (:struct hgestureinfo)))
    (p-gesture-info (:pointer (:struct pgestureinfo))))

(cffi:defcfun (get-gesture-extra-args "GetGestureExtraArgs" :convention :stdcall :library "user32.dll")
    :int
    (h-gesture-info (:pointer (:struct hgestureinfo)))
    (cb-extra-args :uint)
    (p-extra-args (:pointer :int8)))

(cffi:defcfun (close-gesture-info-handle "CloseGestureInfoHandle" :convention :stdcall :library "user32.dll")
    :int
    (h-gesture-info (:pointer (:struct hgestureinfo))))

(cffi:defcstruct gestureconfig
  (dw-id :ulong)
  (dw-want :ulong)
  (dw-block :ulong))

(cffi:defcfun (set-gesture-config "SetGestureConfig" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (dw-reserved :ulong)
    (c-i-ds :uint)
    (p-gesture-config (:pointer (:struct pgestureconfig)))
    (ones (:pointer (:struct previous)))
    (cb-size :uint))

(cffi:defcfun (get-gesture-config "GetGestureConfig" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (dw-reserved :ulong)
    (dw-flags :ulong)
    (pc-i-ds (:pointer :uint))
    (p-gesture-config (:pointer (:struct by)))
    (p-gesture-config (:pointer (:struct pgestureconfig)))
    (structures (:pointer (:struct gestureconfig)))
    (cb-size :uint))

(cffi:defcfun (shutdown-block-reason-create "ShutdownBlockReasonCreate" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (pwsz-reason (:string :encoding :utf-16le)))

(cffi:defcfun (shutdown-block-reason-query "ShutdownBlockReasonQuery" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (pwsz-buff (:string :encoding :utf-16le))
    (pcch-buff :ulong))

(cffi:defcfun (shutdown-block-reason-destroy "ShutdownBlockReasonDestroy" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))

:int
(h-wnd :handle)
(pwsz-buff (:string :encoding :utf-16le))
(pcch-buff :ulong))

(cffi:defcfun (shutdown-block-reason-destroy "ShutdownBlockReasonDestroy" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))
s :uint)
(p-gesture-config (:pointer (:struct pgestureconfig)))
(ones (:pointer (:struct previous)))
(sizeof-gestureconfig (:pointer (:struct //))))

(cffi:defcfun (get-gesture-config "GetGestureConfig" :convention :stdcall :library "user32.dll")
    :int
    (hwnd :handle)
    (dw-reserved :ulong)
    (dw-flags :ulong)
    (pc-i-ds (:pointer :uint))
    (p-gesture-config (:pointer (:struct by)))
    (p-gesture-config (:pointer (:struct pgestureconfig)))
    (structures (:pointer (:struct gestureconfig)))
    (sizeof-gestureconfig (:pointer (:struct //))))

(cffi:defcfun (shutdown-block-reason-create "ShutdownBlockReasonCreate" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (pwsz-reason (:string :encoding :utf-16le)))

(cffi:defcfun (shutdown-block-reason-query "ShutdownBlockReasonQuery" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle)
    (pwsz-buff (:string :encoding :utf-16le))
    (pcch-buff :ulong))

(cffi:defcfun (shutdown-block-reason-destroy "ShutdownBlockReasonDestroy" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))
dcall :library "user32.dll")
:int
(h-wnd :handle))
k-reason-query "ShutdownBlockReasonQuery" :convention :stdcall :library "user32.dll")
:int
(h-wnd :handle)
(pwsz-buff (:string :encoding :utf-16le))
(pcch-buff :ulong))

(cffi:defcfun (shutdown-block-reason-destroy "ShutdownBlockReasonDestroy" :convention :stdcall :library "user32.dll")
    :int
    (h-wnd :handle))
