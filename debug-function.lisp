;-*- mode: lisp; -*-
(in-package :aiku)

(defun format-window-message (header &rest list-of-values &aux lst)
    (declare (optimize (debug 3) (safety 3)) (special lst))
    "output string of formated hex values, list-of-values ::= (msg wparam lparam)"
    (set 'lst '((msg ((#x0000 wm_state)
		      (#x0000 wm_null)
		      (#x0001 wm_create)
		      (#x0002 wm_destroy)
		      (#x0003 wm_move)
		      (#x0005 wm_size)
		      (#x0006 wm_activate wm_activate)
		      (#x0007 wm_setfocus)
		      (#x0008 wm_killfocus)
		      (#x000a wm_enable)
		      (#x000b wm_setredraw)
		      (#x000c wm_settext)
		      (#x000d wm_gettext)
		      (#x000e wm_gettextlength)
		      (#x000f wm_paint)
		      (#x0010 wm_close)
		      (#x0011 wm_queryendsession)
		      (#x0012 wm_quit)
		      (#x0013 wm_queryopen)
		      (#x0014 wm_erasebkgnd)
		      (#x0015 wm_syscolorchange)
		      (#x0016 wm_endsession)
		      (#x0017 wm_systemerror)
		      (#x0018 wm_showwindow)
		      (#x0019 wm_ctlcolor)
		      (#x001a wm_wininichange)
		      (#x001b wm_devmodechange)
		      (#x001c wm_activateapp)
		      (#x001d wm_fontchange)
		      (#x001e wm_timechange)
		      (#x001f wm_cancelmode)
		      (#x0020 wm_setcursor)
		      (#x0021 wm_mouseactivate)
		      (#x0022 wm_childactivate)
		      (#x0023 wm_queuesync)
		      (#x0024 wm_getminmaxinfo)
		      (#x0026 wm_painticon)
		      (#x0027 wm_iconerasebkgnd)
		      (#x0028 wm_nextdlgctl)
		      (#x002a wm_spoolerstatus)
		      (#x002b wm_drawitem)
		      (#x002c wm_measureitem)
		      (#x002d wm_deleteitem)
		      (#x002e wm_vkeytoitem)
		      (#x002f wm_chartoitem)
		      (#x0030 wm_setfont)
		      (#x0031 wm_getfont)
		      (#x0032 wm_sethotkey)
		      (#x0037 wm_querydragicon)
		      (#x0039 wm_compareitem)
		      (#x0041 wm_compacting)
		      (#x0044 wm_commnotify)
		      (#x0046 wm_windowposchanging)
		      (#x0047 wm_windowposchanged)
		      (#x0048 wm_power)
		      (#x004a wm_copydata)
		      (#x004b wm_canceljournal)
		      (#x004e wm_notify)
		      (#x0050 wm_inputlangchangerequest)
		      (#x0051 wm_inputlangchange)
		      (#x0052 wm_tcard)
		      (#x0053 wm_help)
		      (#x0054 wm_userchanged)
		      (#x0055 wm_notifyformat)
		      (#x007b wm_contextmenu)
		      (#x007c wm_stylechanging)
		      (#x007d wm_stylechanged)
		      (#x007e wm_displaychange)
		      (#x007f wm_geticon)
		      (#x0080 wm_seticon)
		      (#x0081 wm_nccreate)
		      (#x0082 wm_ncdestroy)
		      (#x0083 wm_nccalcsize)
		      (#x0084 wm_nchittest)
		      (#x0085 wm_ncpaint)
		      (#x0086 wm_ncactivate)
		      (#x0087 wm_getdlgcode)
		      (#x00a0 wm_ncmousemove)
		      (#x00a1 wm_nclbuttondown)
		      (#x00a2 wm_nclbuttonup)
		      (#x00a3 wm_nclbuttondblclk)
		      (#x00a4 wm_ncrbuttondown)
		      (#x00a5 wm_ncrbuttonup)
		      (#x00a6 wm_ncrbuttondblclk)
		      (#x00a7 wm_ncmbuttondown)
		      (#x00a8 wm_ncmbuttonup)
		      (#x00a9 wm_ncmbuttondblclk)
		      (#x0100 wm_keyfirst)
		      (#x0100 wm_keydown)
		      (#x0101 wm_keyup)
		      (#x0102 wm_char)
		      (#x0103 wm_deadchar)
		      (#x0104 wm_syskeydown)
		      (#x0105 wm_syskeyup)
		      (#x0106 wm_syschar)
		      (#x0107 wm_sysdeadchar)
		      (#x0108 wm_keylast)
		      (#x0110 wm_initdialog)
		      (#x0111 wm_command)
		      (#x0112 wm_syscommand)
		      (#x0113 wm_timer)
		      (#x0114 wm_hscroll)
		      (#x0115 wm_vscroll)
		      (#x0116 wm_initmenu)
		      (#x0117 wm_initmenupopup)
		      (#x0119 wm_gesture)
		      (#x011a wm_gesturenotify)
		      (#x011f wm_menuselect)
		      (#x0120 wm_menuchar)
		      (#x0121 wm_enteridle)
		      (#x0122 wm_menurbuttonup)
		      (#x0123 wm_menudrag)
		      (#x0124 wm_menugetobject)
		      (#x0125 wm_uninitmenupopup)
		      (#x0126 wm_menucommand)
		      (#x0132 wm_ctlcolormsgbox)
		      (#x0133 wm_ctlcoloredit)
		      (#x0134 wm_ctlcolorlistbox)
		      (#x0135 wm_ctlcolorbtn)
		      (#x0136 wm_ctlcolordlg)
		      (#x0137 wm_ctlcolorscrollbar)
		      (#x0138 wm_ctlcolorstatic)
		      (#x0200 wm_mousefirst)
		      (#x0200 wm_mousemove)
		      (#x0201 wm_lbuttondown)
		      (#x0202 wm_lbuttonup)
		      (#x0203 wm_lbuttondblclk)
		      (#x0204 wm_rbuttondown)
		      (#x0205 wm_rbuttonup)
		      (#x0206 wm_rbuttondblclk)
		      (#x0207 wm_mbuttondown)
		      (#x0208 wm_mbuttonup)
		      (#x0209 wm_mbuttondblclk)
		      (#x020a wm_mousewheel)
		      (#x020a wm_mouselast)
		      (#x0210 wm_parentnotify)
		      (#x0211 wm_entermenuloop)
		      (#x0212 wm_exitmenuloop)
		      (#x0213 wm_nextmenu)
		      (#x0214 wm_sizing)
		      (#x0215 wm_capturechanged)
		      (#x0216 wm_moving)
		      (#x0218 wm_powerbroadcast)
		      (#x0219 wm_devicechange)
		      (#x0220 wm_mdicreate)
		      (#x0221 wm_mdidestroy)
		      (#x0222 wm_mdiactivate)
		      (#x0223 wm_mdirestore)
		      (#x0224 wm_mdinext)
		      (#x0225 wm_mdimaximize)
		      (#x0226 wm_mditile)
		      (#x0227 wm_mdicascade)
		      (#x0228 wm_mdiiconarrange)
		      (#x0229 wm_mdigetactive)
		      (#x0230 wm_mdisetmenu)
		      (#x0231 wm_entersizemove)
		      (#x0232 wm_exitsizemove)
		      (#x0233 wm_dropfiles)
		      (#x0234 wm_mdirefreshmenu)
		      (#x0281 wm_ime_setcontext)
		      (#x0282 wm_ime_notify)
		      (#x0283 wm_ime_control)
		      (#x0284 wm_ime_compositionfull)
		      (#x0285 wm_ime_select)
		      (#x0286 wm_ime_char)
		      (#x0290 wm_ime_keydown)
		      (#x0291 wm_ime_keyup)
		      (#x02a1 wm_mousehover)
		      (#x02a3 wm_mouseleave)
		      (#x0300 wm_cut)
		      (#x0301 wm_copy)
		      (#x0302 wm_paste)
		      (#x0303 wm_clear)
		      (#x0304 wm_undo)
		      (#x0305 wm_renderformat)
		      (#x0306 wm_renderallformats)
		      (#x0307 wm_destroyclipboard)
		      (#x0308 wm_drawclipboard)
		      (#x0309 wm_paintclipboard)
		      (#x030a wm_vscrollclipboard)
		      (#x030b wm_sizeclipboard)
		      (#x030c wm_askcbformatname)
		      (#x030d wm_changecbchain)
		      (#x030e wm_hscrollclipboard)
		      (#x030f wm_querynewpalette)
		      (#x0310 wm_paletteischanging)
		      (#x0311 wm_palettechanged)
		      (#x0312 wm_hotkey)
		      (#x0317 wm_print)
		      (#x0318 wm_printclient)
		      (#x0358 wm_handheldfirst)
		      (#x035f wm_handheldlast)
		      (#x0360 wm_afxfirst)
		      (#x037f wm_afxlast)
		      (#x0380 wm_penwinfirst)
		      (#x038f wm_penwinlast)
		      (#x0390 wm_coalesce_first)
		      (#x039f wm_coalesce_last)
		      (#x0400 wm_user)))
		(wm_size ((0 size_restored)
			  (1 size_minimized)
			  (2 size_maximized)
			  (3 size_maxshow)
			  (4 size_maxhide)))
		(wm_activate ((0 wa_inactive)
			      (1 wa_active)
			      (2 wa_clickactive)))
		(wm_showwindow ((1 sw_parentclosing)
				(2 sw_otherzoom)
				(3 sw_parentopening)
				(4 sw_otherunzoom)))
		(wm_mouseactivate ((1 ma_activate)
				   (2 ma_activateandeat)
				   (3 ma_noactivate)
				   (4 ma_noactivateandeat)))
		(wm_mditile ((0 mditile_vertical)
			     (1 mditile_horizontal)
			     (2 mditile_skipdisabled)))
		(wm_notify((-1 nm_outofmemory)
			   (-2 nm_click)
			   (-3 nm_dblclick)
			   (-4 nm_return)
			   (-5 nm_rclick)
			   (-6 nm_rdblclk)
			   (-7 nm_setfocus)
			   (-8 nm_killfocus)))
		(wm_seticon ((0 icon_small)
			     (1 icon_big)))
		(wm_hotkey ((#x01 hotkeyf_shift)
			    (#x02 hotkeyf_control)
			    (#x04 hotkeyf_alt)
			    (#x08 hotkeyf_ext)))
		(keystroke ((#x0100 kf_extended)
			    (#x0800 kf_dlgmode)
			    (#x1000 kf_menumode)
			    (#x2000 kf_altdown)
			    (#x4000 kf_repeat)
			    (#x8000 kf_up)))
		(key-state ((#x01 mk_lbutton)
			    (#x02 mk_rbutton)
			    (#x04 mk_shift)
			    (#x08 mk_control)
			    (#x10 mk_mbutton)))
		(wm_sizing ((1 wmsz_left)
			    (2 wmsz_right)
			    (3 wmsz_top)
			    (4 wmsz_topleft)
			    (5 wmsz_topright)
			    (6 wmsz_bottom)
			    (7 wmsz_bottomleft)
			    (8 wmsz_bottomright)))
		(wm_hotkey-modifiers((1 mod_alt)
				     (2 mod_control)
				     (4 mod_shift)
				     (8 mod_win)))
		(wm_print ((#x01 prf_checkvisible)
			   (#x02 prf_nonclient)
			   (#x04 prf_client)
			   (#x08 prf_erasebkgnd)
			   (#x10 prf_children)
			   (#x20 prf_owned)))
		(virtual-key ((#x001 vk_lbutton)
			      (#x003 vk_cancel)
			      (#x002 vk_rbutton)
			      (#x004 vk_mbutton)
			      (#x008 vk_back)
			      (#x009 vk_tab)
			      (#x00c vk_clear)
			      (#x00d vk_return)
			      (#x010 vk_shift)
			      (#x011 vk_control)
			      (#x012 vk_menu)
			      (#x013 vk_pause)
			      (#x014 vk_capital)
			      (#x01b vk_escape)
			      (#x020 vk_space)
			      (#x021 vk_prior)
			      (#x021 vk_pgup)
			      (#x022 vk_pgdn)
			      (#x022 vk_next)
			      (#x023 vk_end)
			      (#x024 vk_home)
			      (#x025 vk_left)
			      (#x026 vk_up)
			      (#x027 vk_right)
			      (#x028 vk_down)
			      (#x029 vk_select)
			      (#x02a vk_print)
			      (#x02b vk_execute)
			      (#x02c vk_snapshot)
			      (#x02d vk_insert)
			      (#x02e vk_delete)
			      (#x02f vk_help)
			      (#x05b vk_lwin)
			      (#x05c vk_rwin)
			      (#x05d vk_apps)
			      (#x060 vk_numpad0)
			      (#x061 vk_numpad1)
			      (#x062 vk_numpad2)
			      (#x063 vk_numpad3)
			      (#x064 vk_numpad4)
			      (#x065 vk_numpad5)
			      (#x066 vk_numpad6)
			      (#x067 vk_numpad7)
			      (#x068 vk_numpad8)
			      (#x069 vk_numpad9)
			      (#x06a vk_multiply)
			      (#x06b vk_add)
			      (#x06c vk_separator)
			      (#x06d vk_subtract)
			      (#x06e vk_decimal)
			      (#x06f vk_divide)
			      (#x070 vk_f1)
			      (#x071 vk_f2)
			      (#x072 vk_f3)
			      (#x073 vk_f4)
			      (#x074 vk_f5)
			      (#x075 vk_f6)
			      (#x076 vk_f7)
			      (#x077 vk_f8)
			      (#x078 vk_f9)
			      (#x079 vk_f10)
			      (#x07a vk_f11)
			      (#x07b vk_f12)
			      (#x07c vk_f13)
			      (#x07d vk_f14)
			      (#x07e vk_f15)
			      (#x07f vk_f16)
			      (#x080 vk_f17)
			      (#x081 vk_f18)
			      (#x082 vk_f19)
			      (#x083 vk_f20)
			      (#x084 vk_f21)
			      (#x085 vk_f22)
			      (#x086 vk_f23)
			      (#x087 vk_f24)
			      (#x090 vk_numlock)
			      (#x091 vk_scroll)
			      (#x0a0 vk_lshift)
			      (#x0a1 vk_rshift)
			      (#x0a2 vk_lcontrol)
			      (#x0a3 vk_rcontrol)
			      (#x0a4 vk_lmenu)
			      (#x0a5 vk_rmenu)
			      (#x0f6 vk_attn)
			      (#x0f7 vk_crsel)
			      (#x0f8 vk_exsel)
			      (#x0f9 vk_ereof)
			      (#x0fa vk_play)
			      (#x0fb vk_zoom)
			      (#x0fc vk_noname)
			      (#x0fd vk_pa1)
			      (#x0fe vk_oem_clear)))))
    (apply #'format
	   (nconc (list *debug-io* (concatenate 'string "~% " header ":  hwnd ~(~8,'0x~)  msg ~(~8,'0x~)  wparam ~(~8,'0x~)  lparam ~(~8,'0x~)"))
		  (cons (car list-of-values)
			(funcall (defun lst (value-list &optional auxi)
				     (when value-list
					 (cons (car (if (and (setq auxi (cadr (assoc auxi lst)))
							     (setq auxi (cdr (assoc (car value-list) auxi))))
							auxi
							value-list))
					       (lst (cdr value-list) (cadr auxi)))))
				 (cdr list-of-values) 'msg)))))

(defun error-message (&optional stream &aux (err-msg (foreign-alloc '(:pointer (:string :encoding :utf-16le)))))
    (declare (optimize (debug 3) (safety 3)))
    "output decoded error message"
    (format-message (+ +format-message-from-system+ +format-message-ignore-inserts+ +format-message-allocate-buffer+)
		    (null-pointer) (get-last-error) #x0 err-msg #x0 (null-pointer))
    (if stream
        (format *debug-io* "~%~A" 
				 (string-right-trim '(#\return #\newline)
						    (foreign-string-to-lisp (mem-ref err-msg :pointer) :encoding :utf-16le)))
	(message-box #x0 (mem-ref err-msg :pointer) "Error message" (+ +mb-iconerror+ +mb-ok+)))
    (local-free (mem-ref err-msg :pointer))
    (foreign-free err-msg))
